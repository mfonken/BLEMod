/*
 * kinetic.c
 *
 *  Created on: Nov 16, 2016
 *      Author: Matthew Fonken
 */

#include "kinetic.h"

#include "../sensors/imu.h"
#include "kalman.h"
#include "matrix.h"

#include "../system/usart_sp.h"


cartesian2_t   vis[2];
double         delta_t;
kinetic_t      kinetics;

void initKinetics( void )
{
	if ( !IMU_Init( I2C0 ) )
	{
		Print_String("No IMU Found.\r\n", 15); /* Display error message on screen. */
	}
	Print_String("IMU Initialized.\r\n", 18);
}
/*! Filter Initializer */
void initFilters( void )
{
    initKalman( &kinetics.rot_f[0], getRoll()  );
    initKalman( &kinetics.rot_f[1], getPitch() );
    initKalman( &kinetics.rot_f[2], getYaw()   );
}

/*! Augment vision data
 \f{eqnarray*}{
    &\mathbf{v} =
    \begin{cases}
        &v_{\hat{i}} = VZ_{\hat{i}} \\
        &v_{\hat{j}} = VZ_{\hat{j}} \\
        &v_{\hat{k}} = VZ_{\hat{k}} \\
    \end{cases} \\
    &\mathbf{v_{true}} = \text{zxyTranform}(\mathbf{v}, \mathbf{a}, 1) \\
    &\mathbf{d_{true}} = \text{zxyTranform}(\mathbf{d}, \mathbf{a}, 1) \\
    &c_{augment} = \frac{D_{beacon}(1 + D_{augment})}{||\mathbf{d_{true}}||} \\
    &\mathbf{v_{return}} =c_{augment}\mathbf{v_{true}}
 \f}
 */
vec3_t *dAugment( vec3_t *dvec,
                  ang3_t *a)
{
    /* Create v vector for zero state */
    vec3_t vvec;       // Vision system vector
    vvec.ihat = VISION_ZSTATE_IHAT;
    vvec.jhat = VISION_ZSTATE_JHAT;
    vvec.khat = VISION_ZSTATE_KHAT; // Defualt is (0,0,-1) or facing down (towards center of gravity)
    //normalizevec3_t(vvec); // normalize if vvec inital isn't of length 1
    /* Transform and normalize v vector by given angles to get unit vector from camera */
    vec3_t *vtru = zxyTransform( &vvec, a, 0 );

    /* Transform d vector by given angles to get true vector between beacons */
    vec3_t *dtru = zxyTransform( dvec, a, 0 );

    /* Calculate estimated augmentation of v vector
     by ratio of transformed true d estimation and real (BEACON_DISTANCE) */
    double aug = ( BEACON_DISTANCE * ( 1 + D_AUG ) ) / lengthOfvec3_t( dtru ) ;

    /* Apply augmentation and return */
    vtru->ihat *= aug;
    vtru->jhat *= aug;
    vtru->khat *= aug;
    return vtru;
}

/*! Get absolute position
 \f{eqnarray*}{
    &a_a = rot_{f_0}, a_b = rot_{f_1}, a_c = rot_{f_2} \\

    &\mathbf{d} =
    \begin{cases}
        &d_{\hat{i}} = vis_{1_x} - vis_{0_x} \\
        &d_{\hat{j}} = vis_{1_y} - vis_{0_y} \\
        &d_{\hat{k}} = 0 \\
    \end{cases} \\
    &\mathbf{r} = \text{dAugment}(\mathbf{d}, \mathbf{a}) \\
    &\mathbf{e} =
    \begin{cases}
        &e_{\hat{i}} = V_{center_x} - vis_{0_x} \\
        &e_{\hat{j}} = V_{center_y} - vis_{0_y} \\
        &e_{\hat{k}} = 0 \\
    \end{cases} \\
    &\mathbf{e_{true}} = \text{zxyTranform}(\mathbf{e}, \mathbf{a}, 1) \\
    &\mathbf{p_{true}} = \mathbf{r} - \mathbf{e_{true}} \\
    &\mathbf{n} = \text{getNonGravAcceleration()} \\
    &\mathbf{v} =
    \begin{cases}
        &v_x = &n_{\hat{i}}\Delta{t} \\
        &v_y = &n_{\hat{j}}\Delta{t} \\
        &v_z = &n_{\hat{k}}\Delta{t} \\
    \end{cases} \\
    &\text{Update all position kalman_ts with } \mathbf{p_{true}}, \mathbf{v}, \text{ and } \Delta{t}
 \f}
 */
void getAbsolutePosition( void )
{
    /* Tait-Bryan angles of vision */
    ang3_t tba;
    tba.a = kinetics.rot_f[0].value;
    tba.b = kinetics.rot_f[1].value;
    tba.c = kinetics.rot_f[2].value;

    /* vector from B1 in vision -TO-> B2 in vision */
    vec3_t dvec;
    dvec.ihat = vis[1].x - vis[0].x;
    dvec.jhat = vis[1].y - vis[0].y;
    dvec.khat = 0;                             // d is only on XY plane (surface of beacons)

    /* Create r vector (camera -TO-> vision center) from augment generated true d and vision d */
    vec3_t rvec = *( dAugment( &dvec, &tba ) );

    /* vector between vision center -TO-> B1 */
    vec3_t evec;
    evec.ihat = VISION_CENTER_X - vis[0].x;
    evec.jhat = VISION_CENTER_Y - vis[0].y;
    evec.khat = 0;                             // e is only on XY plane (surface of beacons)

    /* vector between vision center -TO-> B2 */
//    vec3_t fvec;
//    fvec.ihat = VISION_CENTER_X - vis[1].x;
//    fvec.jhat = VISION_CENTER_Y - vis[1].y;
//    fvec.khat = 0;                             // f is only on XY plane (surface of beacons)

    /* Transform e vector (vision center -TO-> B1) to true e vector (transformed vision center -TO-> true B1) */
    vec3_t etru = *( zxyTransform( &evec, &tba, 1 ) );

    /* Subract true e vector from augmented r vector */
    subtractvec3_ts(&rvec, &etru);

    kinetics.tru[0] = rvec.ihat;
    kinetics.tru[1] = rvec.jhat;
    kinetics.tru[2] = rvec.khat;

    /* Filter calculated absolute position and with integrated acceleration (velocity) */
    ang3_t * ang;
    ang->a = kinetics.rot_f[0].value;
    ang->b = kinetics.rot_f[1].value;
    ang->c = kinetics.rot_f[2].value;
    vec3_t *ngacc = getNonGravAcceleration( ang );
    double delta_time = 0; // Insert RTCC
    double x_vel = ngacc->ihat * delta_time;
    updateKalman( &kinetics.tru_f[0], kinetics.tru[0], x_vel, delta_time);
    double y_vel = ngacc->jhat * delta_time;
    updateKalman( &kinetics.tru_f[1], kinetics.tru[1], y_vel, delta_time);
    double z_vel = ngacc->khat * delta_time;
    updateKalman( &kinetics.tru_f[2], kinetics.tru[2], z_vel, delta_time);
}

/*! IMU even handler */
void IMU_Update( void )
{
	uint16_t imu_data[12];
    IMU_Read(I2C0, imu_data);

    double theta = getPitch();
    double phi   = getRoll();
    double psi   = getYaw();

    double kalman_t_temp = kinetics.rot_f[0].value;
    if ((theta < -HALF_PI && kalman_t_temp > HALF_PI) || (theta > HALF_PI && kalman_t_temp < -HALF_PI))
    {
    	kinetics.rot_f[1].value  = theta;
    	kinetics.rot[1]          = theta;
    }
    else
    {
        updateKalman( &kinetics.rot_f[1], theta, gyro[1], delta_t ); // Calculate the true pitch using a kalman_t filter
        kinetics.rot[1] = kinetics.rot_f[1].value;
    }

    kalman_t_temp = absl(kinetics.rot_f[1].value);
    if (kalman_t_temp > HALF_PI)
    {
        gyro[0] = -gyro[0]; // Invert rate, so it fits the restricted accelerometer reading
    }
    updateKalman( &kinetics.rot_f[0], phi, gyro[0], delta_t ); // Calculate the true roll using a kalman_t filter
    kinetics.rot[0] = kinetics.rot_f[0].value;

    updateKalman( &kinetics.rot_f[2], psi, gyro[2], delta_t ); // Calculate the true yaw using a kalman_t filter
}
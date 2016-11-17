/*
 * matrix_types.h
 *
 *  Created on: Nov 16, 2016
 *      Author: Matthew Fonken
 */

#ifndef KINETIC_KINETIC_TYPES_H_
#define KINETIC_KINETIC_TYPES_H_

/*! Kalman structure */
typedef struct _kalman_t
{
    double  K[2];                /**< Gain matrix */
    double  P_k[2][2];           /**< Error covariance matrix */
    double  rate;                /**< Rate */
    double  bias;                /**< Bias */
    double  value;               /**< Value */
    double timestamp;           /**< Timestamp */
} kalman_t;

/*! Kinetic Type */
typedef struct _kinetic_t
{
    double     pos[3];
    double     rot[3];
    double     tru[3];

    kalman_t   pos_f[3];
    kalman_t   rot_f[3];
    kalman_t   tru_f[3];
} kinetic_t;


typedef struct _cartesian2_t
{
    double x;
    double y;
} cartesian2_t;

/*! Tait-Bryan Angles */
typedef struct _ang3_t
{
    double    a;
    double    b;
    double    c;
} ang3_t;

/*! Simple 3d Vector */
typedef struct _vec3_t
{
    double    ihat;
    double    jhat;
    double    khat;
} vec3_t;

#endif /* KINETIC_KINETIC_TYPES_H_ */

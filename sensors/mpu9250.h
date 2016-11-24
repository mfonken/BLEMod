/***********************************************************************************************//**
 * \file   imu.h
 * \brief  IMU Control Header
 ***************************************************************************************************
 *      Author: Matthew Fonken
 **************************************************************************************************/

#ifndef IMU_H_
#define IMU_H_

/* Standard headers */
#include <stdbool.h>

/* em headers */
#include "em_device.h"

/* Included types header */
#include "kinetic_types.h"

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup imu
 * @{
 **************************************************************************************************/


#define IMU_ADDR 	0xd4
#define IMU_ID	 	0x69


extern uint8_t acc[3];
extern uint8_t gyro[3];


/***************************************************************************************************
 Local Functions
 **************************************************************************************************/

/**************************************************************************//**
 * \brief Get IMU Register
 * \param[out] Return value from register
 * \param[in] reg Register to access
 *****************************************************************************/
uint8_t 	IMU_GetRegister( uint8_t reg );

/**************************************************************************//**
 * \brief Set IMU Register
 * \param[in] reg Register to access
 * \param[in] val Value to set
 *****************************************************************************/
void 		IMU_SetRegister( uint8_t reg, uint8_t val );

/**************************************************************************//**
 * \brief Reset Local Settings to Default
 ******************************************************************************
 * NOTE: This does not physically set on the IMU, just the local variable
 *****************************************************************************/
void 		IMU_Default( void );

/**************************************************************************//**
 * \brief Initialize IMU with local settings
 * \param[out] Initialization success
 *****************************************************************************/
bool 		IMU_Init( void );

/**************************************************************************//**
 * \brief Read IMU accel and gyro data
 * \param[in] read_data Array to store read data
 *****************************************************************************/
void 	 	IMU_Read( uint16_t *read_data );

/**************************************************************************//**
 * \brief Convert accelerometer data to readable double value
 * \param[out] Return converted value 
 * \param[in] data Raw value from register
 *****************************************************************************/
double 		convertAccel( uint16_t data );

/**************************************************************************//**
 * \brief Convert gyroscope data to readable double value
 * \param[out] Return converted value
 * \param[in] data Raw value from register
 *****************************************************************************/
double 		convertGyro( uint16_t data );

/**************************************************************************//**
 * \brief Get roll angle (phi) from accelerometer data
 * \param[out] Return roll
 *****************************************************************************/
double 		getRoll( void );

/**************************************************************************//**
 * \brief Get roll angle (phi) error from accelerometer data
 * \param[out] Return roll error
 *****************************************************************************/
double      getRollError( void )

/**************************************************************************//**
 * \brief Get pitch angle (theta) from accelerometer data
 * \param[out] Return pitch
 *****************************************************************************/
double 		getPitch( void );

/**************************************************************************//**
 * \brief Get yaw angle (psi) from magnetometer data, pitch, and roll
 * \param[out] Return yaw
 *****************************************************************************/
double      getYaw( void )

/**************************************************************************//**
 * \brief Get no gravitation acceleration from accelerometer data
 * \param[out] Return 3D vector of acceleration
 * \param[in] tba Tait-Bryan angles to transform by
 *****************************************************************************/
vec3_t * 	getNonGravAcceleration( ang3_t * tba );

/**************************************************************************//**
 * \brief Read temperature from register
 * \param[out] Return raw temperature data
 *****************************************************************************/
uint16_t 	IMU_ReadTemp( void );

/**************************************************************************//**
 * \brief Read temperature in Fahrenheit
 * \param[out] Return corrected temperature data as readable double
 *****************************************************************************/
double 		getTempF( void );

/**************************************************************************//**
 * \brief Read temperature in Celsius
 * \param[out] Return corrected temperature data as readable double
 *****************************************************************************/
double 		getTempC( void );

/***************************************************************************************************
 Local Types
 **************************************************************************************************/

/** FIFO Mode Options */
enum fifo_modes
{
	BYPASS_MODE             = 0,
	FIFO_ACTIVE_MODE        = 1,
	CONTINUOUS_MODE         = 6,
	CONT_TO_FIFO_MODE       = 3,
	BYPASS_TO_CONT_MODE     = 4,
};


/***************************************************************************************************
 Local Structures
 **************************************************************************************************/



/** IMU General Settings */
typedef struct _IMU_General_Settings
{
    uint8_t
    uint8_t fsync_en;
} IMU_General_Settings;

/** IMU FIFO Settings */
typedef struct _IMU_FIFO_Settings
{
    uint16_t  sampleRate;               /**< FIFO sample rate           */
    uint16_t  threshold;                /**< FIFO collection threshold  */
    fifo_mode mode;                     /**< FIFO mode                  */
} IMU_FIFO_Settings;

/** IMU Gyroscope Settings */
typedef struct _IMU_Gyro_Settings
{
    bool  	 enabled;                   /**< Gyro enable control        */
    uint16_t scale;                     /**< Gyro dps scale             */
    uint16_t fchoice;                   /**< Gyro fchoice               */
} IMU_Gyro_Settings;

/** IMU Accelerometer Settings */
typedef struct _IMU_Accel_Settings
{
    bool  	 enabled;                   /**< Accel enable control       */
    uint8_t  scale;                     /**< Accel dps range            */
    uint8_t  fchoice;                   /**< Accel bandwidth            */
    uint8_t  dlpfConfig;
    //bool	 dataReadyEnabled;          /**< Accel data ready enable    */
};

/** IMU Settings */
typedef struct _IMU_Settings
{
    IMU_General_Settings 	general;    /**< IMU general settings       */
    IMU_FIFO_Settings  		fifo;       /**< IMU FIFO settings          */
    IMU_Gyro_Settings  		gyro;       /**< IMU gyro settings          */
    IMU_Accel_Settings 		accel;      /**< IMU accel settings         */
} IMU_Settings;

/** @} (end addtogroup imu) */
/** @} (end addtogroup Application) */

#endif /* IMU_H_ */

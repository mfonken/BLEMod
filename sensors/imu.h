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
 * \brief Get roll angle from accelerometer data
 * \param[out] Return value
 *****************************************************************************/
double 		getRoll( void );

/**************************************************************************//**
 * \brief Get pitch angle from accelerometer data
 * \param[out] Return value
 *****************************************************************************/
double 		getPitch( void );

/**************************************************************************//**
 * \brief Get yaw angle from accelerometer data
 * \param[out] Return value
 *****************************************************************************/
double 		getYaw( void );

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
/** Accelerometer Bandwidth Options */
enum accel_bandwidths
{
	ACCEL_BANDWIDTH_50HZ    = 0x03,
	ACCEL_BANDWIDTH_100HZ   = 0x02,
	ACCEL_BANDWIDTH_200HZ   = 0x01,
	ACCEL_BANDWIDTH_400HZ   = 0x00,
};
/** Accelerometer Scale Options */
enum accel_scales
{
	ACCEL_SCALE_2G          = 0x03,
	ACCEL_SCALE_4G          = 0x08,
	ACCEL_SCALE_8G          = 0x0c,
	ACCEL_SCALE_16G         = 0x04,
};
/** Accelerometer Data Rate Options */
enum accel_data_rate
{
	ACCEL_DATA_RATE_PWDN  	= 0x00,
	ACCEL_DATA_RATE_13HZ  	= 0x10,
	ACCEL_DATA_RATE_26HZ  	= 0x20,
	ACCEL_DATA_RATE_52HZ  	= 0x30,
	ACCEL_DATA_RATE_104HZ  	= 0x40,
	ACCEL_DATA_RATE_208HZ  	= 0x50,
	ACCEL_DATA_RATE_416HZ  	= 0x60,
	ACCEL_DATA_RATE_833HZ  	= 0x70,
	ACCEL_DATA_RATE_1660HZ  = 0x80,
	ACCEL_DATA_RATE_3330HZ  = 0x90,
	ACCEL_DATA_RATE_6660HZ  = 0xA0,
	ACCEL_DATA_RATE_13330HZ = 0xB0,
};
/** Gyroscope Scale Options */
enum gyro_scales
{
	GYRO_SCALE_125DPS       = 0x00,
	GYRO_SCALE_245DPS       = 0x03,
	GYRO_SCALE_500DPS       = 0x08,
	GYRO_SCALE_1000DPS      = 0x0c,
	GYRO_SCALE_2000DPS      = 0x04,
};
/** Gyroscope Data Rate Options */
enum gryo_data_rate
{
	GYRO_DATA_RATE_PWDN  	= 0x00,
	GYRO_DATA_RATE_13HZ  	= 0x10,
	GYRO_DATA_RATE_26HZ  	= 0x20,
	GYRO_DATA_RATE_52HZ  	= 0x30,
	GYRO_DATA_RATE_104HZ  	= 0x40,
	GYRO_DATA_RATE_208HZ  	= 0x50,
	GYRO_DATA_RATE_416HZ  	= 0x60,
	GYRO_DATA_RATE_833HZ  	= 0x70,
	GYRO_DATA_RATE_1660HZ  	= 0x80,
};

/** FIFO Mode Options */
enum fifo_mode
{
	BYPASS_MODE             = 0,
	FIFO_ACTIVE_MODE        = 1,
	CONTINUOUS_MODE         = 6,
	CONT_TO_FIFO_MODE       = 3,
	BYPASS_TO_CONT_MODE     = 4,
};

/** Default Setting Values */
enum defaultValue
{
	TEMP_ENABLED            = true,

	FIFO_THRESHOLD          = 3000,
	FIFO_SAMPLE_RATE        = 10,
	FIFO_MODE               = BYPASS_MODE,

	GYRO_ENABLE             = true,
	GYRO_RANGE              = 2000,
	GYRO_SAMPLE_RATE        = 416,
	GYRO_BANDWIDTH          = 400,
	GYRO_FIFO_EN            = true,
	GYRO_FIFO_DEC           = true,

	ACCEL_ENABLE            = true,
	ACCEL_RANGE             = 16,
	ACCEL_SAMPLE_RATE       = 416,
	ACCEL_BANDWIDTH         = 100,
	ACCEL_FIFO_EN           = true,
	ACCEL_FIFO_DEC          = true,
};

/** IMU Register Addresses */
enum regAddr
{
	FUNC_CFG_ACCESS         = 0x01,

	FIFO_CTRL1              = 0x06,
	FIFO_CTRL2              = 0x07,
	FIFO_CTRL3              = 0x08,
	FIFO_CTRL4              = 0x09,
	FIFO_CTRL5              = 0x0A,
	ORIENT_CFG_G            = 0x0B,

	INT1_CTRL               = 0x0D,
	INT2_CTRL               = 0x0E,
	WHO_AM_I                = 0x0F,
	CTRL1_XL                = 0x10,
	CTRL2_G                 = 0x11,
	CTRL3_C                 = 0x12,
	CTRL4_C                 = 0x13,
	CTRL5_C                 = 0x14,
	CTRL6_C                 = 0x15,
	CTRL7_G                 = 0x16,
	CTRL8_XL                = 0x17,
	CTRL9_XL                = 0x18,
	CTRL10_C                = 0x19,

	WAKE_UP_SRC             = 0x1B,
	TAP_SRC                 = 0x1C,
	D6D_SRC                 = 0x1D,
	STATUS_REG              = 0x1E,

	OUT_TEMP_L              = 0x20,
	OUT_TEMP_H              = 0x21,
	OUTX_L_G                = 0x22,
	OUTX_H_G                = 0x23,
	OUTY_L_G                = 0x24,
	OUTY_H_G                = 0x25,
	OUTZ_L_G                = 0x26,
	OUTZ_H_G                = 0x27,
	OUTX_L_XL               = 0x28,
	OUTX_H_XL               = 0x29,
	OUTY_L_XL               = 0x2A,
	OUTY_H_XL               = 0x2B,
	OUTZ_L_XL               = 0x2C,
	OUTZ_H_XL               = 0x2D,

	FIFO_STATUS1            = 0x3A,
	FIFO_STATUS2            = 0x3B,
	FIFO_STATUS3            = 0x3C,
	FIFO_STATUS4            = 0x3D,
	FIFO_DATA_OUT_L         = 0x3E,
	FIFO_DATA_OUT_H         = 0x3F,
	TIMESTAMP0_REG          = 0x40,
	TIMESTAMP1_REG          = 0x41,
	TIMESTAMP2_REG          = 0x42,

	STEP_TIMESTAMP_L        = 0x49,
	STEP_TIMESTAMP_H        = 0x4A,
	STEP_COUNTER_L          = 0x4B,
	STEP_COUNTER_H          = 0x4C,

	FUNC_SRC                = 0x53,

	TAP_CFG                 = 0x58,
	TAP_THS_6D              = 0x59,
	INT_DUR2                = 0x5A,
	WAKE_UP_THS             = 0x5B,
	WAKE_UP_DUR             = 0x5C,
	FREE_FALL               = 0x5D,
	MD1_CFG                 = 0x5E,
	MD2_CFG                 = 0x5F,
};

/***************************************************************************************************
 Local Structures
 **************************************************************************************************/
/** IMU General Settings */
typedef struct _IMU_General_Settings
{
    bool 	temperatureEnabled;         /**< Temperature enabled        */
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
    uint16_t range;                     /**< Gyro dps range             */
    uint16_t sampleRate;                /**< Gyro sample rate           */
    uint16_t bandWidth;                 /**< Gryo bandwidth             */
    bool  	 fifoEnabled;               /**< FIFO gyro control          */
    bool  	 fifoDecimation;            /**< FIFO gyro decimation       */
} IMU_Gyro_Settings;

/** IMU Accelerometer Settings */
typedef struct _IMU_Accel_Settings
{
    bool  	 enabled;                   /**< Accel enable control       */
    bool	 dataReadyEnabled;          /**< Accel data ready enable    */
    uint16_t range;                     /**< Accel dps range            */
    uint16_t sampleRate;                /**< Accel sample rate          */
    uint16_t bandWidth;                 /**< Accel bandwidth            */
    bool  	 fifoEnabled;               /**< FIFO accel control         */
    bool  	 fifoDecimation;            /**< FIFO accel decimation      */
} IMU_Accel_Settings;

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

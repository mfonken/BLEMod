/**
 *
 * \file i2c.h
 *
 *  Created on: Nov 13, 2016
 *      Author: Matthew Fonken
 */

#ifndef IMU_H_
#define IMU_H_

#include <stdbool.h>
#include "em_device.h"

#include "kinetic_types.h"

#define IMU_ADDR 	0xd4
#define IMU_ID	 	0x69

#define MU          0.1

extern uint8_t acc[3];
extern uint8_t gyro[3];



typedef struct _IMU_General_Settings
{
	bool 	temperatureEnabled;
} IMU_General_Settings;

typedef struct _IMU_FIFO_Settings
{
	uint16_t sampleRate;
	uint16_t threshold;
	uint8_t  mode;
} IMU_FIFO_Settings;

typedef struct _IMU_Gyro_Settings
{
	bool  	 enabled;
	uint16_t range;
	uint16_t sampleRate;
	uint16_t bandWidth;
	bool  	 fifoEnabled;
	bool  	 fifoDecimation;
} IMU_Gyro_Settings;

typedef struct _IMU_Accel_Settings
{
	bool  	 enabled;
	bool	 dataReadyEnabled;
	uint16_t range;
	uint16_t sampleRate;
	uint16_t bandWidth;
	bool  	 fifoEnabled;
	bool  	 fifoDecimation;
} IMU_Accel_Settings;

typedef struct _IMU_Settings
{
	IMU_General_Settings 	general;
	IMU_FIFO_Settings  		fifo;
	IMU_Gyro_Settings  		gyro;
	IMU_Accel_Settings 		accel;
} IMU_Settings;

bool 		IMU_Default( void );
bool 		IMU_Init( void );
uint8_t 	IMU_ReadRegister( uint8_t reg );
bool 		IMU_SetRegister( uint8_t reg, uint8_t val );
bool 	 	IMU_Read( uint16_t *read_data );

double 		convertAccel( uint16_t data );
double 		convertGyro( uint16_t data );
double 		getRoll( void );
double 		getPitch( void );
double 		getYaw( void );
vec3_t * 	getNonGravAcceleration( ang3_t * tba );

uint16_t 	IMU_ReadTemp( void );
double 		getTempF( void );

enum accel_bandwidths
{
	ACCEL_BANDWIDTH_50HZ  = 0x03,
	ACCEL_BANDWIDTH_100HZ = 0x02,
	ACCEL_BANDWIDTH_200HZ = 0x01,
	ACCEL_BANDWIDTH_400HZ = 0x00,
};
enum accel_scales
{
	ACCEL_SCALE_2G  	  = 0x03,
	ACCEL_SCALE_4G  	  = 0x08,
	ACCEL_SCALE_8G  	  = 0x0c,
	ACCEL_SCALE_16G  	  = 0x04,
};
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

enum gyro_scales_non_125
{
	GYRO_SCALE_125DPS	  = 0x00,
	GYRO_SCALE_245DPS 	  = 0x03,
	GYRO_SCALE_500DPS  	  = 0x08,
	GYRO_SCALE_1000DPS 	  = 0x0c,
	GYRO_SCALE_2000DPS 	  = 0x04,
};
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

enum regDefaults
{
	CTRL1_XL_D 		= 0x80,
	CTRL2_G_D 		= 0x80,
	CTRL3_C_D 		= 0x04,
};

enum fifo_modes
{
	BYPASS_MODE 		= 0,
	FIFO_ACTIVE_MODE	= 1,
	CONTINUOUS_MODE 	= 6,
	CONT_TO_FIFO_MODE	= 3,
	BYPASS_TO_CONT_MODE = 4,
};

enum defaultValues
{
	TEMP_ENABLED		= true,

	FIFO_THRESHOLD		= 3000,
	FIFO_SAMPLE_RATE	= 10,
	FIFO_MODE			= BYPASS_MODE,

	GYRO_ENABLE 		= true,
	GYRO_RANGE 			= 2000,
	GYRO_SAMPLE_RATE	= 416,
	GYRO_BANDWIDTH		= 400,
	GYRO_FIFO_EN		= true,
	GYRO_FIFO_DEC		= true,

	ACCEL_ENABLE		= true,
	ACCEL_RANGE			= 16,
	ACCEL_SAMPLE_RATE	= 416,
	ACCEL_BANDWIDTH		= 100,
	ACCEL_FIFO_EN		= true,
	ACCEL_FIFO_DEC		= true,
};

// register addresses
enum regAddr
{
	FUNC_CFG_ACCESS   = 0x01,

	FIFO_CTRL1        = 0x06,
	FIFO_CTRL2        = 0x07,
	FIFO_CTRL3        = 0x08,
	FIFO_CTRL4        = 0x09,
	FIFO_CTRL5        = 0x0A,
	ORIENT_CFG_G      = 0x0B,

	INT1_CTRL         = 0x0D,
	INT2_CTRL         = 0x0E,
	WHO_AM_I          = 0x0F,
	CTRL1_XL          = 0x10,
	CTRL2_G           = 0x11,
	CTRL3_C           = 0x12,
	CTRL4_C           = 0x13,
	CTRL5_C           = 0x14,
	CTRL6_C           = 0x15,
	CTRL7_G           = 0x16,
	CTRL8_XL          = 0x17,
	CTRL9_XL          = 0x18,
	CTRL10_C          = 0x19,

	WAKE_UP_SRC       = 0x1B,
	TAP_SRC           = 0x1C,
	D6D_SRC           = 0x1D,
	STATUS_REG        = 0x1E,

	OUT_TEMP_L        = 0x20,
	OUT_TEMP_H        = 0x21,
	OUTX_L_G          = 0x22,
	OUTX_H_G          = 0x23,
	OUTY_L_G          = 0x24,
	OUTY_H_G          = 0x25,
	OUTZ_L_G          = 0x26,
	OUTZ_H_G          = 0x27,
	OUTX_L_XL         = 0x28,
	OUTX_H_XL         = 0x29,
	OUTY_L_XL         = 0x2A,
	OUTY_H_XL         = 0x2B,
	OUTZ_L_XL         = 0x2C,
	OUTZ_H_XL         = 0x2D,

	FIFO_STATUS1      = 0x3A,
	FIFO_STATUS2      = 0x3B,
	FIFO_STATUS3      = 0x3C,
	FIFO_STATUS4      = 0x3D,
	FIFO_DATA_OUT_L   = 0x3E,
	FIFO_DATA_OUT_H   = 0x3F,
	TIMESTAMP0_REG    = 0x40,
	TIMESTAMP1_REG    = 0x41,
	TIMESTAMP2_REG    = 0x42,

	STEP_TIMESTAMP_L  = 0x49,
	STEP_TIMESTAMP_H  = 0x4A,
	STEP_COUNTER_L    = 0x4B,
	STEP_COUNTER_H    = 0x4C,

	FUNC_SRC          = 0x53,

	TAP_CFG           = 0x58,
	TAP_THS_6D        = 0x59,
	INT_DUR2          = 0x5A,
	WAKE_UP_THS       = 0x5B,
	WAKE_UP_DUR       = 0x5C,
	FREE_FALL         = 0x5D,
	MD1_CFG           = 0x5E,
	MD2_CFG           = 0x5F,
};

#endif /* IMU_H_ */

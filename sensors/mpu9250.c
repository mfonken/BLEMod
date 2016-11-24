/***********************************************************************************************//**
 * \file   mpu9250.c
 * \brief  IMU Control
 ***************************************************************************************************
 *      Author: Matthew Fonken
 **************************************************************************************************/

/* Standard headers */
#include <stddef.h>
#include <math.h>

/* em headers */
#include "em_i2c.h"

/* Additional function headers */
#include "i2c_sp.h"

/* Own header */
#include "mpu9250.h"

/* Math headers */
#include "matrix.h"

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup imu
 * @{
 **************************************************************************************************/

/***************************************************************************************************
 Macros
 **************************************************************************************************/
#define sign(x) x > 0 ? 1:-1

/***************************************************************************************************
 Local Variables
 **************************************************************************************************/
IMU_Settings settings;

/***************************************************************************************************
 Local Functions
 **************************************************************************************************/
/**************************************************************************//**
 * \brief IMU_GetRegister
 * \param[out] Return value from register
 * \param[in] reg Register to access
 *****************************************************************************/
uint8_t IMU_GetRegister( regAddr reg )
{
	uint8_t i2c_read_data[1];
	I2C_Read( IMU_ADDR, reg, i2c_read_data, 1 );
	return i2c_read_data[0];
}

/**************************************************************************//**
 * \brief IMU_SetRegister
 * \param[in] reg Register to access
 * \param[in] val Value to set
 *****************************************************************************/
void IMU_SetRegister( regAddr reg, uint8_t val )
{
	uint8_t i2c_write_data[2];
	i2c_write_data[0] = reg;
	i2c_write_data[0] = val;
	I2C_Write( IMU_ADDR, i2c_write_data, 2 );
}

/***************************************************************************************************
 Initialization
 **************************************************************************************************/

/**************************************************************************//**
 * \brief Reset Local Settings to Default
 ******************************************************************************
 * NOTE: This does not physically set on the IMU, just the local variable
 *****************************************************************************/
bool IMU_Default( void )
{
	settings.general.temperatureEnabled = TEMP_ENABLED;
	settings.fifo.threshold				= FIFO_THRESHOLD;
	settings.fifo.sampleRate			= FIFO_SAMPLE_RATE;
	settings.fifo.mode					= FIFO_MODE;
	settings.gyro.enabled				= GYRO_ENABLE;
	settings.gyro.range					= GYRO_RANGE;
	settings.gyro.sampleRate			= GYRO_SAMPLE_RATE;
	settings.gyro.bandWidth				= GYRO_BANDWIDTH;
	settings.gyro.fifoEnabled			= GYRO_FIFO_EN;
	settings.gyro.fifoDecimation		= GYRO_FIFO_DEC;
	settings.accel.enabled				= ACCEL_ENABLE;
	settings.accel.range				= ACCEL_RANGE;
	settings.accel.sampleRate			= ACCEL_SAMPLE_RATE;
	settings.accel.bandWidth			= ACCEL_BANDWIDTH;
	settings.accel.fifoEnabled			= ACCEL_FIFO_EN;
	settings.accel.fifoDecimation		= ACCEL_FIFO_DEC;
}

/**************************************************************************//**
 * \brief Initialize IMU with local settings
 * \param[out] Initialization success
 *****************************************************************************/
bool IMU_Init( void )
{
    /* Ensure IMU is connected and correct */
	uint8_t i2c_read_data[1];
	I2C_Read( IMU_ADDR, WHO_AM_I, i2c_read_data, 1 );
	if( i2c_read_data[0] != IMU_ID )
	{
		return false;
	}

    /* Get default settings */
	IMU_Default();

    /* Set accel settings */
	uint8_t options = 0;
	if( settings.accel.enabled )
	{
		switch( settings.accel.bandWidth )
		{
		case 50:
			options |= ACCEL_BANDWIDTH_50HZ;
			break;
		case 100:
			options |= ACCEL_BANDWIDTH_100HZ;
			break;
		case 200:
			options |= ACCEL_BANDWIDTH_200HZ;
			break;
		default:
		case 400:
			options |= ACCEL_BANDWIDTH_400HZ;
			break;
		}
		switch( settings.accel.range )
		{
		case 2:
			options |= ACCEL_SCALE_2G;
			break;
		case 4:
			options |= ACCEL_SCALE_4G;
			break;
		case 8:
			options |= ACCEL_SCALE_8G;
			break;
		default:
		case 16:
			options |= ACCEL_SCALE_16G;
			break;
		}
		switch( settings.accel.sampleRate )
		{
		case 13:
			options |= ACCEL_DATA_RATE_13HZ;
			break;
		case 26:
			options |= ACCEL_DATA_RATE_26HZ;
			break;
		case 52:
			options |= ACCEL_DATA_RATE_52HZ;
			break;
		default:
		case 104:
			options |= ACCEL_DATA_RATE_104HZ;
			break;
		case 208:
			options |= ACCEL_DATA_RATE_208HZ;
			break;
		case 416:
			options |= ACCEL_DATA_RATE_416HZ;
			break;
		case 833:
			options |= ACCEL_DATA_RATE_833HZ;
			break;
		case 1660:
			options |= ACCEL_DATA_RATE_1660HZ;
			break;
		case 3330:
			options |= ACCEL_DATA_RATE_3330HZ;
			break;
		case 6660:
			options |= ACCEL_DATA_RATE_6660HZ;
			break;
		case 13330:
			options |= ACCEL_DATA_RATE_13330HZ;
			break;
		}
	}
	else
	{
		options |= ACCEL_DATA_RATE_PWDN;
	}
	IMU_SetRegister( CTRL1_XL, options);

    /* Set gyro settings */
	options = 0;
	if( settings.gyro.enabled )
	{
		switch( settings.gyro.sampleRate )
		{
		case 13:
			options |= GYRO_DATA_RATE_13HZ;
			break;
		case 26:
			options |= GYRO_DATA_RATE_26HZ;
			break;
		case 52:
			options |= GYRO_DATA_RATE_52HZ;
			break;
		case 104:
			options |= GYRO_DATA_RATE_104HZ;
			break;
		case 208:
			options |= GYRO_DATA_RATE_208HZ;
			break;
		case 416:
			options |= GYRO_DATA_RATE_416HZ;
			break;
		case 833:
			options |= GYRO_DATA_RATE_833HZ;
			break;
		case 1660:
			options |= GYRO_DATA_RATE_1660HZ;
			break;
		}
	}
	else
	{
		options |= GYRO_DATA_RATE_PWDN;
	}
	IMU_SetRegister( CTRL2_G, options );
	return true;
}



/******************************************************************************
 * Motion Data Access
 *****************************************************************************/

/**************************************************************************//**
 * \brief Read IMU accel and gyro data
 * \param[in] read_data Array to store read data
 *****************************************************************************/
bool IMU_Read( uint16_t *read_data )
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t                    i2c_write_data[1];
	uint8_t                    i2c_read_data[12];

	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select command to issue */
	i2c_write_data[0] = OUTX_L_G;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 1;
	/* Select location/length of data to be read */
	seq.buf[1].data = i2c_read_data;
	seq.buf[1].len  = 12;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}

	/* Combine low and high byte values */
	for( int i = 0; i < 6 ; i++ )
	{
		read_data[i] = ( i2c_read_data[( i * 2 ) + 1] << 8 ) + i2c_read_data[( i * 2 )];
	}

	return true;
}

/**************************************************************************//**
 * \brief Convert accelerometer data to readable double value
 * \param[out] Return converted value
 * \param[in] data Raw value from register
 *****************************************************************************/
double convertAccel( uint16_t data )
{
	return ( double )( data * 0.061 * (settings.accel.range >> 1) / 1000 );
}

/**************************************************************************//**
 * \brief Convert gyroscope data to readable double value
 * \param[out] Return converted value
 * \param[in] data Raw value from register
 *****************************************************************************/
double convertGyro( uint16_t data )
{
    uint8_t rangeDivisor = settings.gyroRange / 125;
    if ( settings.gyroRange == 245 ) {
        rangeDivisor = 2;
    }
	return ( double )data * 4.375 * ( rangeDivisor ) / 1000;
}

/******************************************************************************
 * Rotation Calculation
 *****************************************************************************/
/* See - http://www.nxp.com/files/sensors/doc/app_note/AN3461.pdf and
       - http://www.nxp.com/assets/documents/data/en/application-notes/AN4248.pdf
 */

/**************************************************************************//**
 * \brief Get roll angle (phi) from accelerometer data
 * \param[out] Return roll
 *****************************************************************************/
double getRoll( void )
{
    double den = sqrt( ( ( acc[1] * acc[1] ) + ( acc[2] * acc[2] ) ) );
    return atan2( -acc[0], den );
}
/**************************************************************************//**
 * \brief Get roll angle (phi) error from accelerometer data
 * \param[out] Return roll error
 *****************************************************************************/
double getRollError( void )
{
    double sin_phi   = sin( this.roll );
    double sin_theta = sin( this.pitch );
    double cos_phi   = cos( this.roll );
    double cos_theta = cos( this.pitch );
    double cos_theta_cos_phi = cos_theta * cos_phi;
    double mu_sin_2_theta = MU * ( sin_theta * sin_theta );
    double factor = sqrt( ( cos_theta_cos_phi * cos_theta_cos_phi ) + mu_sin_2_theta );
    double num = sin_phi * ( cos_theta_cos_phi - factor );
    double den = ( cos_theta * ( sin_phi * sin_phi ) ) + ( cos_phi * factor );
    return atan2( num, den );
}

/**************************************************************************//**
 * \brief Get pitch angle (theta) from accelerometer data
 * \param[out] Return pitch
 *****************************************************************************/
double getPitch( void )
{
    double den = sign( acc[2] ) * sqrt( ( ( acc[2] * acc[2] ) + ( MU * ( acc[0] * acc[0] ) ) ) );
    return atan2( acc[1], den );
}

/**************************************************************************//**
 * \brief Get yaw angle (psi) from magnetometer data, pitch, and roll
 * \param[out] Return yaw
 *****************************************************************************/
double getYaw( void )
{
    double sin_phi   = sin( this.roll );
    double sin_theta = sin( this.pitch );
    double cos_phi   = cos( this.roll );
    double cos_theta = cos( this.pitch );
    double num = ( mag[2] * sin_phi ) - ( mag[1] * cos_phi );
    double den = ( mag[0] * cos_theta ) + ( mag[1] * ( sin_theta * sin_phi ) ) + ( mag[2] * ( sin_theta * cos_phi ) );
    return atan2( num, den );
}

/**************************************************************************//**
 * \brief Get no gravitation acceleration from accelerometer data
 * \param[out] Return 3D vector of acceleration
 * \param[in] tba Tait-Bryan angles to transform by
 *****************************************************************************/
vec3_t * getNonGravAcceleration( ang3_t * tba )
{
    /* Create a vector of accelerometer values */
    vec3_t avec;
    avec.ihat = acc[0];
    avec.jhat = acc[1];
    avec.khat = acc[2];

    /* Transform and normalize v vector by given angles to get unit vector from camera */
    vec3_t * atru = zxyTransform( &avec, tba, 1 );

    atru->khat += 1; // Negate gravity
    return atru;
}

/******************************************************************************
 * Temperature
 *****************************************************************************/

/**************************************************************************//**
 * \brief Read temperature from register
 * \param[out] Return raw temperature data
 *****************************************************************************/
uint16_t IMU_ReadTemp( void )
{
	uint16_t tempurature;
	tempurature  = IMU_ReadRegister( OUT_TEMP_H ) << 8;
	tempurature += IMU_ReadRegister( OUT_TEMP_L );
	return tempurature;
}

/**************************************************************************//**
 * \brief Read temperature in Fahrenheit
 * \param[out] Return corrected temperature data as readable double
 *****************************************************************************/
double getTempF( void )
{
	return ( double )( ( IMU_ReadTemp() / 16 ) + 25 );;
}

/**************************************************************************//**
 * \brief Read temperature in Celsius
 * \param[out] Return corrected temperature data as readable double
 *****************************************************************************/
double getTempC( void )
{
    return ( double )( ( getTempF() * ( 5 / 9 ) ) - 32 );;
}

/** @} (end addtogroup imu) */
/** @} (end addtogroup Application) */

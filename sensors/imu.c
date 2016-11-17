/***********************************************************************************************//**
 * \file   imu.c
 * \brief  IMU Functions
 **************************************************************************************************/

#include <stddef.h>
#include <math.h>

#include "em_i2c.h"

#include "imu.h"
#include "matrix.h"

#define sign(x) x > 0 ? 1:-1

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup imu
 * @{
 **************************************************************************************************/

/***************************************************************************************************
 Local Functions
 **************************************************************************************************/
/** IMU_Init */
bool IMU_Init(I2C_TypeDef *i2c)
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t                    i2c_write_data[2];
	uint8_t                    i2c_read_data[1];

	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select command to issue */
	i2c_write_data[0] = WHO_AM_I;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 1;
	/* Select location/length of data to be read */
	seq.buf[1].data = i2c_read_data;
	seq.buf[1].len  = 1;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	if( i2c_read_data[0] != IMU_ID )
	{
		return false;
	}

	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	/* Select command to issue */
	i2c_write_data[0] = CTRL1_XL;
	i2c_write_data[1] = CTRL1_XL_D;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 2;
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	/* Select command to issue */
	i2c_write_data[0] = CTRL2_G;
	i2c_write_data[1] = CTRL2_G_D;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 2;
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE;
	/* Select command to issue */
	i2c_write_data[0] = CTRL3_C;
	i2c_write_data[1] = CTRL3_C_D;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 2;
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	return true;
}

/**************************************************************************//**

 *****************************************************************************/
/** IMU_Read */
bool IMU_Read( I2C_TypeDef *i2c, uint16_t *read_data )
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

 *****************************************************************************/
/** IMU_ReadTemp */
uint16_t IMU_ReadTemp( I2C_TypeDef *i2c )
{
	uint16_t tempurature;
	tempurature  = IMU_ReadRegister( I2C0, OUT_TEMP_H ) << 8;
	tempurature += IMU_ReadRegister( I2C0, OUT_TEMP_L );
	return tempurature;
}

/**************************************************************************//**

 *****************************************************************************/
/** IMU_ReadRegister */
uint8_t IMU_ReadRegister( I2C_TypeDef *i2c, uint8_t reg )
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t                    i2c_read_data[1];
	uint8_t                    i2c_write_data[1];

	seq.addr  = IMU_ADDR;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select command to issue */
	i2c_write_data[0] = reg;
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = 1;
	/* Select location/length of data to be read */
	seq.buf[1].data = i2c_read_data;
	seq.buf[1].len  = 1;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	return i2c_read_data[0];
}

/**************************************************************************//**

 *****************************************************************************/
/** IMU_SetRegister */
bool IMU_SetRegister( I2C_TypeDef *i2c, uint8_t reg, uint8_t val )
{
	return I2CSP_SetRegister(i2c, IMU_ADDR, reg, val);
}

/**************************************************************************//**

 *****************************************************************************/
/** I2CSP_SetRegister */
bool I2CSP_SetRegister( I2C_TypeDef *i2c, uint8_t addr, uint8_t reg, uint8_t val )
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t                    i2c_write_data[1];

	seq.addr  = addr;
	seq.flags = I2C_FLAG_WRITE;
	/* Select command to issue */
	i2c_write_data[0] 	= reg;
	i2c_write_data[1] 	= val;
	seq.buf[0].data   	= i2c_write_data;
	seq.buf[0].len    	= 2;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	return true;
}


/* See - http://www.nxp.com/files/sensors/doc/app_note/AN3461.pdf */

/*! Get roll from IMU data */
double getRoll()
{
	double y = sign( acc[2] ) * sqrt( ( acc[2] * acc[2] ) + ( MU * ( acc[0] * acc[0] ) ) );
    return atan2( acc[1], y ); // Eqn. 38
}

/*! Get pitch from IMU data */
double getPitch()
{
    return atan( -acc[0] / sqrt( ( acc[1] * acc[1] ) + ( acc[2] * acc[2] ) ) ); // Eqn. 37
}

/*! Get yaw from IMU data */
double getYaw()
{
    return atan( -acc[2] / sqrt( ( acc[0] * acc[0] ) + ( acc[1] * acc[1] ) ) ); // Eqn. 37
}

/*! Find acceleration apart from gravity */
vec3_t * getNonGravAcceleration( ang3_t * tba )
{
    /* Tait-Bryan angles of vision */

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

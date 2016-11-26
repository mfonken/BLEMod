/***********************************************************************************************//**
* \file   mpu9250_regs.h
* \brief  MPU9250 registers initialization
***************************************************************************************************
*      Author: Matthew Fonken
**************************************************************************************************/


#include <stdio.h>
#include "mpu9250_regs.h"

/***************************************************************************************************
 Local Variables
 **************************************************************************************************/

/***************************************************************************************************
 Local Functions
 **************************************************************************************************/

/**************************************************************************//**
 * \brief Get register value from MPU9250
 * \param[out] Return value from register
 * \param[in] reg Register to access
 *****************************************************************************/
uint8_t mpu9250_GetRegister( regAddr reg )
{
    uint8_t i2c_read_data[1];
    I2C_Read( IMU_ADDR, reg, i2c_read_data, 1 );
    return i2c_read_data[0];
}

/**************************************************************************//**
 * \brief Set register value on MPU9250
 * \param[in] reg Register to access
 * \param[in] val Value to set
 *****************************************************************************/
void mpu9250_SetRegister( regAddr reg, uint8_t val )
{
    uint8_t i2c_write_data[2];
    i2c_write_data[0] = reg;
    i2c_write_data[0] = val;
    I2C_Write( IMU_ADDR, i2c_write_data, 2 );
}

/**************************************************************************//**
 * \brief Get register value from MPU9250 Magnometer
 * \param[out] Return value from register
 * \param[in] reg Register to access
 *****************************************************************************/
uint8_t mpu9250_GetMagRegister( regAddr reg )
{
    uint8_t i2c_read_data[1];
    I2C_Read( MAG_ADDR, reg, i2c_read_data, 1 );
    return i2c_read_data[0];
}

/**************************************************************************//**
 * \brief Set register value on MPU9250 Magnometer
 * \param[in] reg Register to access
 * \param[in] val Value to set
 *****************************************************************************/
void mpu9250_SetMagRegister( regAddr reg, uint8_t val )
{
    uint8_t i2c_write_data[2];
    i2c_write_data[0] = reg;
    i2c_write_data[0] = val;
    I2C_Write( MAG_ADDR, i2c_write_data, 2 );
}

/**************************************************************************//**
 * \brief Initialize MPU9250 with default values
 *****************************************************************************/
void mpu9250_defaultInit( mpu9250_global_t * this )
{
    this.config.general.fifoMode   = FIFO_MODE_DEFAULT;
    this.config.general.fsyncMode  = EXT_FSYNC_MODE_DEFAULT;
    this.config.general.dlpfConfig = GYRO_BW_DEFAULT;
    
    if( GYRO_BW_DEFAULT <= 0x07 )
    {
        this.config.gyro.fchoice  = GYRO_BW_ENABLE;
    }
    else
    {
        this.config.gyro.fchoice  = GYRO_BW_DEFAULT && GYRO_BW_MASK;
    }
    this.config.gyro.fscale        = GYRO_FS_DEFAULT;
    this.config.gyro.enable        = GYRO_EN_ENABLE;
    
    this.config.accel.dlpfConfig   = ACCEL_BW_DEFAULT
    if( ACCEL_BW_DEFAULT <= 0x07 )
    {
        this.config.accel.fchoice  = ENABLE;
    }
    else
    {
        this.config.accel.fchoice  = DISABLE;
    }
    this.config.accel.fscale       = ACCEL_FS_DEFAULT;
    this.config.accel.enable       = ACCEL_EN_DEFAULT;
    
    this.config.interrupt          = INT_PIN_DEFAULT;
    
    
    this.control.accel_lp          = ACCEL_LP_ODR_240HZ;
    this.control.accel_int         = ACCEL_INTEL_DEFAULT;
    this.control.fifo_en           = FIFO_ENABLE_DEFAULT;
    this.control.int_en            = INT_ENABLE_DEFAULT;
    this.control.int_status        = INT_STATUS_DEFAULT;
    this.control.usr_ctrl          = USER_CONFIG_DEFAULT;
    this.control.pwr_mgmt          = PWR_MGMT_DEFAULT;
    
    mpu9250_updateRegisters();
}

/**************************************************************************//**
 * \brief Update MPU9250 registers with current global configuration
 *****************************************************************************/
void mpu9250_updateRegisters( void )
{
    mpu9250_SetRegister( CONFIG,          this.config.general           );
    mpu9250_SetRegister( GYRO_CONFIG,     this.config.gyro              );
    mpu9250_SetRegister( ACCEL_CONFIG_2,  this.config.accel << 0xFF     );
    mpu9250_SetRegister( ACCEL_CONFIG,    this.config.accel && 0xFF     );
    mpu9250_SetRegister( INT_PIN_CFG,     this.config.interrupt         );
    
    mpu9250_SetRegister( LP_ACCEL_ODR,    this.control.accel_lp         );
    mpu9250_SetRegister( MOT_DETECT_CTRL, this.control.accel_int        );
    mpu9250_SetRegister( FIFO_EN,         this.control.fifo_en          );
    mpu9250_SetRegister( INT_ENABLE,      this.control.int_en           );
    mpu9250_SetRegister( INT_STATUS,      this.control.int_status       );
    mpu9250_SetRegister( USER_CTRL,       this.control.usr_ctrl         );
    
    mpu9250_SetRegister( PWR_MGMT_2,      this.control.pwr_mgmt << 0xFF );
    mpu9250_SetRegister( PWR_MGMT_1,      this.control.pwr_mgmt && 0xFF );
}

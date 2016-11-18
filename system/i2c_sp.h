/*
 * i2c_sp.h
 *
 *  Created on: Nov 17, 2016
 *      Author: Matthew Fonken
 */

#ifndef SYSTEM_I2C_SP_H_
#define SYSTEM_I2C_SP_H_

bool I2C_Read( uint8_t addr, uint8_t reg, uint8_t *i2c_read_data, uint8_t i2c_read_data_length);
bool I2C_Write( uint8_t addr, uint8_t *i2c_write_data, uint8_t i2c_write_data_length);

#endif /* SYSTEM_I2C_SP_H_ */

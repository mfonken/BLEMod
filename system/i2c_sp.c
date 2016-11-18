/*
 * i2c_sp.c
 *
 *  Created on: Nov 17, 2016
 *      Author: Matthew Fonken
 */

/* Standard headers */
#include <stdbool.h>

/* em headers */
#include "em_i2c.h"

/* Own header */
#include "i2c_sp.h"

bool I2C_Read( uint8_t addr, uint8_t reg, uint8_t *i2c_read_data, uint8_t i2c_read_data_length)
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;

	seq.addr  = addr;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select command to issue */
	seq.buf[0].data   = &reg;
	seq.buf[0].len    = 1;
	/* Select location/length of data to be read */
	seq.buf[1].data = i2c_read_data;
	seq.buf[1].len  = i2c_read_data_length;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	return ret;
}

bool I2C_Write( uint8_t addr, uint8_t *i2c_write_data, uint8_t i2c_write_data_length)
{
	I2C_TransferSeq_TypeDef    seq;
	I2C_TransferReturn_TypeDef ret;
	uint8_t                    i2c_read_data[1];

	seq.addr  = addr;
	seq.flags = I2C_FLAG_WRITE;
	/* Select command to issue */
	seq.buf[0].data   = i2c_write_data;
	seq.buf[0].len    = i2c_write_data_length;

	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress)
	{
		ret = I2C_Transfer(I2C0);
	}
	return ret;
}


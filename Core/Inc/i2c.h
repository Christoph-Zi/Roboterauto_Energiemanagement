/*
 * i2c.h
 *
 * Created on: Apr 28, 2020
 * Author: Gion-Pol Catregn (FHGR)
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"

/********************************************************************************************/
/* Global Variables                                                                         */
/********************************************************************************************/


/********************************************************************************************/
/* Functions                                                                                */
/********************************************************************************************/
uint8_t I2C_Scanner(uint8_t i2cAddrBuf[]);
void I2C_Read_Register(uint8_t address, uint16_t reg, uint8_t *data);
void I2C_Write_Register(uint8_t address, uint16_t reg, uint8_t data);
void I2C_Read_FIFO(uint8_t address, uint8_t reg, uint16_t size);

uint8_t data;

#endif /* INC_I2C_H_ */

/*
 * ioExpander.c
 *
 *  Created on: Oct 12, 2021
 *  Author: Jan Schuessler, FHGR
 *  Board: STM32 NUCLEO-F401RE
 *  Description: Driver for the PCA9554B IO Expander
 */

#include "main.h"
#include <stdio.h>
#include "ioExpander.h"

extern I2C_HandleTypeDef hi2c1;

static HAL_StatusTypeDef ret;
static uint8_t DevAddress = 0x20 << 1;
static uint8_t REG_config = 0x03;
static uint8_t REG_input = 0x00;
static uint8_t REG_output = 0x01;


static int i2cWrite(uint8_t DevAddress, uint8_t reg, uint8_t data) {
	/*
	 * writes one byte 'data' to register 'reg'
	 */
	uint8_t buf[2];
	buf[0] = reg; // write register to first array position
	buf[1] = data; // write data to second array position
	ret = HAL_I2C_Master_Transmit(&hi2c1, DevAddress, buf, 2, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C Error\r\n");
		return 1;
	} else {
		return 0;
	}
}

static int i2cRead(uint8_t DevAddress, uint8_t reg, uint8_t *data, uint8_t size) {
	/*
	 * reads 'size' registers, starting from register 'reg', stores bytes in 'data'
	 */
	data[0] = reg; // write register to read
	ret = HAL_I2C_Master_Transmit(&hi2c1, DevAddress, data, 1, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C Error\r\n");
		return 1;
	}
	ret = HAL_I2C_Master_Receive(&hi2c1, DevAddress, data, size, HAL_MAX_DELAY);
	if (ret != HAL_OK) {
		printf("I2C Error\r\n");
		return 1;
	}
	return 0;
}

void ioExp_initPin(uint8_t input_output, uint8_t pin){
	/* param input_output: 1 to set pin as input, 0 for output
	 * param pin: pin 0-7
	 */
	uint8_t val[1];
	i2cRead(DevAddress, REG_config, val, 1);

	if(input_output){
		val[0] = val[0] | (0b00000001 << pin); // write '1' to according bit (corresponds with pin number)
	} else{
		val[0] = val[0] & ~(0b00000001 << pin); // write '0' to according bit (corresponds with pin number)
	}

	i2cWrite(DevAddress, REG_config, val[0]);
}

void ioExp_writePin(uint8_t high_low, uint8_t pin){
	/*
	 * set pin state
	 */
	uint8_t val[1];
	i2cRead(DevAddress, REG_output, val, 1);

	if(high_low){
		val[0] = val[0] | (0b00000001 << pin);
	} else{
		val[0] = val[0] & ~(0b00000001 << pin);
	}

	i2cWrite(DevAddress, REG_output, val[0]);
}

uint8_t ioExp_readPin(uint8_t pin){
	/*
	 * read pin state
	 */
	uint8_t val[1];
	i2cRead(DevAddress, REG_input, val, 1);

	val[0] = val[0] & (0b00000001 << pin);
	return val[0] >> pin;
}

uint8_t ioExp_readOutputs(){
	/*
	 * read all pin states
	 */
	uint8_t val[1];
	i2cRead(DevAddress, REG_output, val, 1);
	return val[0];
}
void ioExp_writeOutputs(uint8_t val){
	/*
	 * write all pins
	 */
	i2cWrite(DevAddress, REG_output, val);
}


void ioExp_init(void)
{
	uint8_t val;

	i2cRead(DevAddress, REG_config, val, 1);

	printf("CONFIG Register = 0x%x\r\n",val);

	val = 0b10100000;

	i2cWrite(DevAddress, REG_config, val);

	i2cRead(DevAddress, REG_config, val, 1);

	printf("CONFIG Register = 0x%x\r\n",val);

	val = 0b00000000;

	i2cWrite(DevAddress, REG_output, val);

	ioExp_writePin(1, LEDS_FL);
	HAL_Delay(200);
	ioExp_writePin(0, LEDS_FL);
	HAL_Delay(200);
	ioExp_writePin(1, LEDS_FR);
	HAL_Delay(200);
	ioExp_writePin(0, LEDS_FR);
	HAL_Delay(200);
	ioExp_writePin(1, LEDS_RL);
	HAL_Delay(200);
	ioExp_writePin(0, LEDS_RL);
	HAL_Delay(200);
	ioExp_writePin(1, LEDS_RR);
	HAL_Delay(200);
	ioExp_writePin(0, LEDS_RR);

}

void toggleFrontLEDs(void)
{
	if(ioExp_readPin(LEDS_FL) && ioExp_readPin(LEDS_FR))
	{
		ioExp_writePin(0, LEDS_FL);
		ioExp_writePin(0, LEDS_FR);
	}
	else
	{
		ioExp_writePin(1, LEDS_FL);
		ioExp_writePin(1, LEDS_FR);
	}
}

void toggleRearLEDs(void)
{
	if(ioExp_readPin(LEDS_RL) && ioExp_readPin(LEDS_RR))
	{
		ioExp_writePin(0, LEDS_RL);
		ioExp_writePin(0, LEDS_RR);
	}
	else
	{
		ioExp_writePin(1, LEDS_RL);
		ioExp_writePin(1, LEDS_RR);
	}
}

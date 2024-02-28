/*
This file contains some function for I2C communication

  * Autor: Gion-Pol Catregn (FHGR)
  * Date: 07.04.2020
  * Version: 1.0
  * Changes:
  * 07.04.2020 V1.0 Initial Version
*/


/********************************************************************************************/
/* Includes                                                                                 */
/********************************************************************************************/

#include "main.h"
//#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>


/********************************************************************************************/
/* Local Variables                                                                          */
/********************************************************************************************/
extern I2C_HandleTypeDef hi2c1;	// Handler for the I2C communication
HAL_StatusTypeDef result;	// Variable for the HAL status
uint8_t i2cBuf[32];			// I2C Buffer Array

/********************************************************************************************/
 /* Functions                                                                               */
/********************************************************************************************/

// This Function scans the I2c bus for connected devices
// Parameters: None
// Return: None
uint8_t I2C_Scanner(uint8_t i2cAddrBuf[])
{
	printf("Scanning I2C bus:\r\n"); // Output to the serial console
	// Scan all addresses
   	uint8_t i;
   	uint8_t devCnt=0;
   	for (i=1; i<128; i++)
   	{
   		// Check if there is a response on the corresponding address
   		result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 2);
   		if (result != HAL_OK) // HAL_ERROR or HAL_BUSY or HAL_TIMEOUT
   		{
   			//printf(".\r"); // No ACK received at that address
   		}
   		if (result == HAL_OK)
   		{
   			printf("\nDevice found at address : 0x%X\r\n", i); // Received an ACK at that address
   			i2cAddrBuf[devCnt] = i;
   			devCnt++;
   		}
   		HAL_Delay(50); // Delay of 50ms
   	}
   	printf("\r\n");
   	return devCnt;
}

// This Function reads one register over I2C
// Parameters: Device address, Register to read
// Return: The byte stored in the register
I2C_Read_Register(uint8_t address, uint16_t reg, uint8_t *data)
{
	//uint8_t buf[2]; // Buffer containing the data
	i2cBuf[0] = reg >> 8; // Store the register to the buffer
	i2cBuf[1] = reg & 0xFF;
	result = HAL_I2C_Master_Transmit(&hi2c1, address, i2cBuf, 2, HAL_MAX_DELAY); // Write the register address over i2c
	if ( result != HAL_OK )
	{

	}
	else
	{
		result = HAL_I2C_Master_Receive(&hi2c1, address, i2cBuf, 1, HAL_MAX_DELAY); //Reads the data and stores it to the buffer
		if ( result != HAL_OK ) {

		}
		else
		{
			//printf("Register read done!\r\n");
		}
	}
	*data = i2cBuf[0]; // return the read register
}

// This Function reads a burst of data over I2C
// Parameters: Device address, Register to read, Size of bytes to read
// Return: Data is stored in a global array
void I2C_Read_FIFO(uint8_t address, uint8_t reg, uint16_t size)
{

	/*fifoData[0] = reg; // Store the register to the array
	result = HAL_I2C_Master_Transmit(&hi2c1, address, fifoData, 1, HAL_MAX_DELAY); // Write the register address over i2c
	if ( result != HAL_OK )
	{

	}
	else
	{
		result = HAL_I2C_Master_Receive(&hi2c1, address, fifoData, size, HAL_MAX_DELAY); // Store the bytes to the global array
		if ( result != HAL_OK ) {

		}
		else
		{
			//printf("FIFO read done!\r\n");
		}
	}
	*/
}

// This Function writes 1byte of data over I2C
// Parameters: Device address, Register to write, data of the byte
// Return: None
void I2C_Write_Register(uint8_t address, uint16_t reg, uint8_t data)
{
	// Store the register and the data to the buffer
	i2cBuf[0] = reg >> 8; // Store the register to the buffer
	i2cBuf[1] = reg & 0xFF;
	i2cBuf[2] = data;
	result = HAL_I2C_Master_Transmit(&hi2c1, address, i2cBuf, 3, HAL_MAX_DELAY);// Write the buffer over i2c
	if ( result != HAL_OK )
	{

	}
	else
	{

		printf("Register write done!\r\n");

	}

}


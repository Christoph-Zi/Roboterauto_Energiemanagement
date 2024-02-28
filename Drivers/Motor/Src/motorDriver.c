/*
 * motorDriver.c
 *
 *  Created on: 12.10.2021
 *      Author: catreggionpo
 */

#include "main.h"

extern TIM_HandleTypeDef htim5;

void setMotorSpeed(uint8_t speed, uint8_t dir)
{
	uint16_t speedTarget = 0;

	speedTarget = speed * 10;

	if (dir)
	{
		HAL_GPIO_WritePin(GPIOC,M3_IN2_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(GPIOC,M3_IN1_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,M3_IN2_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(GPIOC,M3_IN1_Pin, GPIO_PIN_SET);
	}

	htim5.Instance->CCR1 = speedTarget;

}

void accelMotor(uint8_t speed, uint8_t dir)
{
	uint8_t i;
	uint16_t speedTarget = 0;

	speedTarget = speed * 10;

	if (dir)
	{
		HAL_GPIO_WritePin(GPIOC,M3_IN2_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(GPIOC,M3_IN1_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,M3_IN2_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(GPIOC,M3_IN1_Pin, GPIO_PIN_SET);
	}

	//htim5.Instance->CCR1 = 1000;

	for(int i = 100; i<speedTarget; i+=50)
	{
		htim5.Instance->CCR1 = i;
		HAL_Delay(200);
	}

}

void stopMotor(void)
{
	uint16_t actualSpeed = 0;

	actualSpeed = htim5.Instance->CCR1;

	while(actualSpeed > 0)
	{
		actualSpeed -= 50;
		htim5.Instance->CCR1 = actualSpeed;
		HAL_Delay(100);
	}
}


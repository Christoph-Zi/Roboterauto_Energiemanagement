/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "i2c.h"

#include "fonts.h"
#include "ssd1306.h"
#include "bitmap.h"

#include "TOF_driver.h"
#include "vl53lx_api.h"

#include "motorDriver.h"

#include "ioExpander.h"

#include "debugging.h"
#include "bluefruit_controller.h"
#include "bluefruit_plotter.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim5;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */

VL53LX_Dev_t                   dev2;
VL53LX_DEV                     Dev2 = &dev2;
//int status;
int IntCount;
uint8_t rxIntCount;
#define isInterrupt 1
#define isBluetooth 0

uint8_t i2cAddrBuf[10];		// I2C Address Buffer Array

UART_HandleTypeDef *debug_log_huart = NULL;
UART_HandleTypeDef *bluefruit_plotter_huart = NULL;

#define RxBuf_SIZE 10
#define MainBuf_SIZE 20

uint8_t RxBuf[RxBuf_SIZE];
uint8_t MainBuf[MainBuf_SIZE];

uint8_t motorSpeed = 0;
uint8_t motorDirection = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM5_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
//void RangingLoop(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin==ST_TOF_INT_Pin)
  {
    IntCount++;
  }
}

void handle_buttons(int number, int is_pressed)
{
	DEBUG_LOG("Bluefruit controller: Button %i was %s\r\n",
			number, (is_pressed == 1) ? "pressed" : "released");

	switch (number)
	{
		case 5:
			if (is_pressed)
			{
				if (motorDirection == 1)
				{
					motorSpeed += 10;
					setMotorSpeed(motorSpeed,motorDirection);
				}
				else
				{
					stopMotor();
					motorSpeed = 0;
					motorDirection = 1;
				}
			}
			else
			{
				setMotorSpeed(motorSpeed,1);
			}
			break;

		case 6:
			if (is_pressed)
			{
				if (motorDirection == 0)
				{
					motorSpeed += 10;
					setMotorSpeed(motorSpeed,motorDirection);
				}
				else
				{
					stopMotor();
					motorSpeed = 0;
					motorDirection = 0;
				}
			}
			else
			{
				setMotorSpeed(motorSpeed,0);
			}
			break;
		case 8:
			if (is_pressed)
			{
				htim3.Instance->CCR2 = 90;
			}
			else
			{
				htim3.Instance->CCR2 = 72;
			}
			break;
		case 7:
			if (is_pressed)
			{
				htim3.Instance->CCR2 = 47;
			}
			else
			{
				htim3.Instance->CCR2 = 72;
			}
			break;
		case 1:
			if (is_pressed)
			{
				toggleFrontLEDs();
			}
			break;
		case 2:
			if (is_pressed)
			{
				toggleRearLEDs();
			}
			break;
	}
}

void handle_gyroscope(float x, float y, float z)
{
	DEBUG_LOG("Bluefruit controller: Gyroscope event (%f, %f, %f)\r\n",
			x, y, z);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{

	rxIntCount++;
	//memcpy (MainBuf, RxBuf, Size);
	//HAL_UARTEx_ReceiveToIdle_DMA(&huart1, RxBuf, RxBuf_SIZE);
	//free(RxBuf);
}




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t devCnt=0;
	//uint16_t wordData;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_TIM5_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */


  HAL_UARTEx_ReceiveToIdle_DMA(&huart1, RxBuf, RxBuf_SIZE);
  __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);


  //bluefruit_plotter_huart = &huart1;
  debug_log_huart = &huart2;

  bluefruit_controller ctrl;
  bluefruit_controller_init(&ctrl, &huart1);
  ctrl.handlers.handle_buttons = handle_buttons;
  ctrl.handlers.handle_gyroscope = handle_gyroscope;


  printf("---------------------------------------\r\n");
  printf("Scanning for I2C Devices\r\n");
  printf("---------------------------------------\r\n");
  printf("\r\n");
  devCnt = I2C_Scanner(i2cAddrBuf);
  printf("%d Devices found\r\n", devCnt);

  for (int i=0; i<devCnt; i++)
  {
	  switch (i2cAddrBuf[i])
	  {
	  	  case 0x29:
	  		printf("TOF sensor found!\r\n");
	  		break;
	  	  case 0x18:
	  		printf("Temperature sensor found!\r\n");
	  		break;
	  	  case 0x20:
	  		printf("IO Expander found!\r\n");
	  		break;
	  	  case 0x3D:
	  		printf("OLED Display found!\r\n");
	  		break;
	  	  case 0x1C:
	  		printf("Gyroscope sensor found!\r\n");
	  		break;
	  	  case 0x6A:
	  		printf("Magnet sensor found!\r\n");
	  		break;
	  }

  }
  printf("\r\n");

  SSD1306_Init();

  //init_adxl343();

  //init_vl53l3cx();

  // Print the FHGR logo to the Display
  SSD1306_DrawBitmap(32, 0,FHGR_LOGO_SW, 64, 64, 1); // Print the logo to the left
  //SSD1306_DrawBitmap(64, 0,HERZ_PULS, 64, 64, 1);	// Pront the heart to the right
  SSD1306_UpdateScreen();							// Update the screen
  //HAL_Delay(2000);
  //SSD1306_Clear();
  //HAL_Delay(5000);


  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);


  //printf("VL53L1X Examples...\n\r");
  //Dev2->I2cHandle = &hi2c1;
  //Dev2->I2cDevAddr = 0x52;

  /* Allow to select the sensor to be used, multi-sensor is not managed in this example.
  Only when use use the Left ToF in interrupt mode,  solder the U7 on the X-Nucleo-53L3A2 board
  Only when use the Right ToF in interrupt mode, solder the U7 on the X-Nucleo-53L3A2 board
  See "Solder drop configurations" in the X-Nucleo-53L3A2 User Manual for more details */
  //ToFSensor = 1; // Select ToFSensor: 0=Left, 1=Center, 2=Right
  //status = XNUCLEO53L3A2_ResetId(ToFSensor, 0); // Reset ToF sensor
  //HAL_Delay(2);
  //status = XNUCLEO53L3A2_ResetId(ToFSensor, 1); // Reset ToF sensor
  //HAL_Delay(2);

  //VL53LX_RdByte(Dev2, 0x010F, &byteData);
  //printf("VL53LX Model_ID: %02X\n\r", byteData);
  //VL53LX_RdByte(Dev2, 0x0110, &byteData);
  //printf("VL53LX Module_Type: %02X\n\r", byteData);
  //VL53LX_RdWord(Dev2, 0x010F, &wordData);
  //printf("VL53LX: %02X\n\r", wordData);



  accelMotor(100,1);

  HAL_Delay(2000);

  stopMotor();

  htim3.Instance->CCR2 = 47;

  HAL_Delay(2000);

  htim3.Instance->CCR2 = 90;
  //htim1.Instance->CCR2 = 90;

  HAL_Delay(2000);

  htim3.Instance->CCR2 = 72;
  //RangingLoop();

  TOF_SensorInit();

  ioExp_init();

  printf("Press the User Button to start!!\r\n");

  SSD1306_Clear();
  SSD1306_DrawBitmap(0, 0,FINGER, 64, 64, 1);
  SSD1306_GotoXY(64, 5);
  SSD1306_Puts("PLEASE", &Font_7x10, 1);
  SSD1306_GotoXY(64, 20);
  SSD1306_Puts("PRESS", &Font_7x10, 1);
  SSD1306_GotoXY(64, 35);
  SSD1306_Puts("USER!", &Font_7x10, 1);
  SSD1306_GotoXY(64, 50);
  SSD1306_Puts("BUTTON!", &Font_7x10, 1);
  SSD1306_UpdateScreen();

  while(ioExp_readPin(B1)==1)
  {

  }



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


	bluefruit_controller_update(&ctrl);


	//HAL_GPIO_WritePin(GPIOC,M3_IN2_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOC,M3_IN1_Pin, GPIO_PIN_SET);

	//htim5.Instance->CCR1 = 0;



	TOF_Measurement();
	HAL_Delay(30);


	/*for(int i = 100; i<1000; i+=50)
	{
		htim5.Instance->CCR1 = i;
		HAL_Delay(1000);
	}*/




  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 1680-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1000-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 42-1;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 1000-1;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */
  HAL_TIM_MspPostInit(&htim5);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|M3_IN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 M3_IN2_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_0|M3_IN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : ST_TOF_INT_Pin */
  GPIO_InitStruct.Pin = ST_TOF_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ST_TOF_INT_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

}

/* USER CODE BEGIN 4 */

/**
* @brief Retargets the C library printf function to the USART.
* @param None
* @retval None
*/
PUTCHAR_PROTOTYPE
{
/* Place your implementation of fputc here */
/* e.g. write a character to the USART2 and Loop until the end of transmission */
if(isBluetooth)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
}
else
{
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
}

return ch;
}

/* ranging and display loop */
/*void RangingLoop(void)
{
  VL53LX_MultiRangingData_t MultiRangingData;
  VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
  uint8_t NewDataReady=0;
  int no_of_object_found=0,j;
  printf("Ranging loop starts\r\n");

  status = VL53LX_WaitDeviceBooted(Dev);
  status = VL53LX_DataInit(Dev);
  status = VL53LX_StartMeasurement(Dev);

  if(status){
    printf("VL53LX_StartMeasurement failed: error = %d \r\n", status);
    while(1);
  }

  if (isInterrupt){
    do // HW interrupt mode
    {
      __WFI();
      if(IntCount !=0 ){
        IntCount=0;
        status = VL53LX_GetMultiRangingData(Dev, pMultiRangingData);
        no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
        printf("Count=%5d, ", pMultiRangingData->StreamCount);
        printf("#Objs=%1d ", no_of_object_found);
        for(j=0;j<no_of_object_found;j++){
          if(j!=0)printf("\n                     ");
          printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps",
                 pMultiRangingData->RangeData[j].RangeStatus,
                 pMultiRangingData->RangeData[j].RangeMilliMeter,
                 pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
                 pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);

          char str[5];
          sprintf(str, "%d", pMultiRangingData->RangeData[j].RangeMilliMeter);

          SSD1306_Clear();
          SSD1306_GotoXY(0, 10);
          SSD1306_Puts(str, &Font_16x26, 1);
          SSD1306_UpdateScreen();
        }
        printf ("\r\n");
        if (status==0){
          status = VL53LX_ClearInterruptAndStartMeasurement(Dev);
        }

      }
    }
    while(1);
  }
  else{
    do{ // polling mode
      status = VL53LX_GetMeasurementDataReady(Dev, &NewDataReady);
      HAL_Delay(1); // 1 ms polling period, could be longer.
      if((!status)&&(NewDataReady!=0)){
        status = VL53LX_GetMultiRangingData(Dev, pMultiRangingData);
        no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
        printf("Count=%5d, ", pMultiRangingData->StreamCount);
        printf("#Objs=%1d ", no_of_object_found);
        for(j=0;j<no_of_object_found;j++){
          if(j!=0)printf("\n                     ");
          printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps",
                 pMultiRangingData->RangeData[j].RangeStatus,
                 pMultiRangingData->RangeData[j].RangeMilliMeter,
                 pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
                 pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);
        }
        printf ("\r\n");
        if (status==0){
          status = VL53LX_ClearInterruptAndStartMeasurement(Dev);
        }
      }
    }
    while (1);
  }
}*/


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

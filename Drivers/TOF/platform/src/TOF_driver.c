/*
 * TOF_driver.c
 *
 *  Created on: Oct 9, 2021
 *      Author: catreggionpo
 */


/* Includes ------------------------------------------------------------------*/
#include <TOF_driver.h>

VL53LX_Dev_t                   dev;
VL53LX_DEV                     Dev = &dev;



extern int IntCount;
#define isInterrupt 1

extern I2C_HandleTypeDef hi2c1;


void TOF_SensorInit(void)
{
	uint8_t byteData;
	int status;

	// Output to Console
	printf("TOF Sensor Initialization\r\n");

	// Define the I2C Handler and the Device Address
	Dev->I2cHandle = &hi2c1;
	Dev->I2cDevAddr = 0x52;

	// Read the Model ID and Type of the TOF Sensor
	VL53LX_RdByte(Dev, 0x010F, &byteData);
	printf("VL53LX Model_ID: %02X\n\r", byteData);
	VL53LX_RdByte(Dev, 0x0110, &byteData);
	printf("VL53LX Module_Type: %02X\n\r", byteData);

	// Wait until the device is booted
	status = VL53LX_WaitDeviceBooted(Dev);
	// Initialization of the TOF Sensor
	status = VL53LX_DataInit(Dev);
	status = VL53LX_StopMeasurement(Dev);
	HAL_Delay(100);

	// Check if the Status is correct
	if(status)
	{
		printf("TOF Sensor Error! = %d \r\n", status);
	}
	else
	{
		printf("TOF Sensor Started!\r\n");
	}

	printf("\r\n");
}


void TOF_Measurement(void)
{
	VL53LX_MultiRangingData_t MultiRangingData;
	VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
	int status;

	int no_of_object_found=0,j;
	 status = VL53LX_ClearInterruptAndStartMeasurement(Dev);
	status = VL53LX_StartMeasurement(Dev);
	HAL_Delay(40);

	__WFI();
	if(IntCount !=0 )
	{
		IntCount=0;
	    status = VL53LX_GetMultiRangingData(Dev, pMultiRangingData);
	    if (status ==0)
	    {
		    no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
		    printf("Count=%5d, ", pMultiRangingData->StreamCount);
		    printf("#Objs=%1d ", no_of_object_found);
		    for(j=0;j<no_of_object_found;j++)
		    {
		    	if(j!=0)printf("\n                     ");
		        printf("status=%d, D=%5dmm, Signal=%2.2f Mcps, Ambient=%2.2f Mcps",
		               pMultiRangingData->RangeData[j].RangeStatus,
		               pMultiRangingData->RangeData[j].RangeMilliMeter,
		               pMultiRangingData->RangeData[j].SignalRateRtnMegaCps/65536.0,
		               pMultiRangingData->RangeData[j].AmbientRateRtnMegaCps/65536.0);

		        char str[5];
		        sprintf(str, "%d", pMultiRangingData->RangeData[j].RangeMilliMeter);

		        SSD1306_Clear();
		        SSD1306_GotoXY(20, 20);
		        SSD1306_Puts(str, &Font_16x26, 1);
		        SSD1306_GotoXY(74, 25);
		        SSD1306_Puts("mm", &Font_11x18, 1);
		        SSD1306_UpdateScreen();
		      }
		      printf ("\r\n");

	    }
	    else
	    {
	    	printf("TOF Measurement Error!!\r\n");
	    }

	}


}




/* ranging and display loop */
void RangingLoop(void)
{
  VL53LX_MultiRangingData_t MultiRangingData;
  VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
  uint8_t NewDataReady=0;
  int no_of_object_found=0,j;
  int status;


  Dev->I2cHandle = &hi2c1;
  Dev->I2cDevAddr = 0x52;

  HAL_I2C_Master_Transmit(&hi2c1, 0x52, 0x0000, 2, 1000);
  HAL_Delay(200);

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
          SSD1306_GotoXY(20, 20);
          SSD1306_Puts(str, &Font_16x26, 1);
          SSD1306_UpdateScreen();
        }
        printf ("\r\n");
        if (status==0){
          status = VL53LX_ClearInterruptAndStartMeasurement(Dev);
        }

      }
      HAL_Delay(500);
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
}

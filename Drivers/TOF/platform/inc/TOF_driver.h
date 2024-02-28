/*
 * TOF_Driver.h
 *
 *  Created on: Oct 9, 2021
 *      Author: catreggionpo
 */

#ifndef TOF_PLATFORM_INC_TOF_DRIVER_H_
#define TOF_PLATFORM_INC_TOF_DRIVER_H_

#include "main.h"
#include "vl53lx_api.h"
#include "fonts.h"
#include "ssd1306.h"
#include "bitmap.h"

void TOF_SensorInit(void);
void TOF_Measurement(void);
void RangingLoop(void);





#endif /* TOF_PLATFORM_INC_TOF_DRIVER_H_ */

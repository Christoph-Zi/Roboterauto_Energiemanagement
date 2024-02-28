#include "bluefruit_plotter.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>



#define BLUEFRUIT_PLOTTER_BUFFER_SIZE 1024



extern UART_HandleTypeDef *bluefruit_plotter_huart;



void bluefruit_plotter(const char *format, ...)
{
	if (bluefruit_plotter_huart == NULL)
		return;

	va_list args;
	va_start(args, format);
	char message[BLUEFRUIT_PLOTTER_BUFFER_SIZE];
	vsnprintf(message, BLUEFRUIT_PLOTTER_BUFFER_SIZE, format, args);
	va_end(args);

	HAL_UART_Transmit(bluefruit_plotter_huart,
		(uint8_t *)message, strlen(message), 1000);
}


#include "debugging.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>



#define DEBUG_LOG_BUFFER_SIZE 1024



extern UART_HandleTypeDef *debug_log_huart;



void debug_log(const char *format, ...)
{
	if (debug_log_huart == NULL)
		return;

	va_list args;
	va_start(args, format);
	char message[DEBUG_LOG_BUFFER_SIZE];
	vsnprintf(message, DEBUG_LOG_BUFFER_SIZE, format, args);
	va_end(args);

	HAL_UART_Transmit(debug_log_huart,
		(uint8_t *)message, strlen(message), 1000);
}

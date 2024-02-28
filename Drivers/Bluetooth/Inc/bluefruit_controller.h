#ifndef INC_BLUEFRUIT_CONTROLLER_H_
#define INC_BLUEFRUIT_CONTROLLER_H_


#include <stdint.h>
#include "stm32f4xx_hal.h"



/// State of the state machine for assembling bytes received from UART to packages
typedef enum
{
	BLUEFRUIT_CONTROLLER_STATE_SKIP = 0,
	BLUEFRUIT_CONTROLLER_STATE_COMMAND,
	BLUEFRUIT_CONTROLLER_STATE_DATA,
	BLUEFRUIT_CONTROLLER_STATE_CRC
} bluefruit_controller_state;

#define BLUEFRUIT_CONTROLLER_BUF_NUMBYTES 20

/// Handlers for different controller commands that are received; can be changed by user
typedef struct
{
	void (*handle_buttons)(int number, int is_pressed);
	void (*handle_gyroscope)(float x, float y, float z);
} bluefruit_event_handlers;

/// State and all status data for assembling bytes received from UART to packages
typedef struct
{
	bluefruit_controller_state state;
	uint8_t buffer[BLUEFRUIT_CONTROLLER_BUF_NUMBYTES];
	size_t buffer_num_bytes;
	size_t num_data_bytes;
	void (*handler)(bluefruit_event_handlers *handlers, uint8_t *);
} bluefruit_controller_status;

typedef struct
{
	UART_HandleTypeDef *huart;
	bluefruit_controller_status status;
	bluefruit_event_handlers handlers;
} bluefruit_controller;



extern void bluefruit_controller_init(bluefruit_controller *ctrl, UART_HandleTypeDef *huart);
extern void bluefruit_controller_update(bluefruit_controller *ctrl);



#endif /* INC_BLUEFRUIT_CONTROLLER_H_ */

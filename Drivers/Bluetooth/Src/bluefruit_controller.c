#include "bluefruit_controller.h"

#include <string.h>

#include "debugging.h"

extern uint8_t rxIntCount;
extern uint8_t RxBuf[10];
extern UART_HandleTypeDef huart1;


typedef struct
{
	// Command short cut, second byte in package
	uint8_t shortcut;
	// Number of bytes between command shortcut and CRC
	size_t num_data_bytes;
	// Handler routine for specific command
	void (*handler)(bluefruit_event_handlers *handlers, uint8_t *);
} bluefruit_controller_command;

void handle_buttons_raw(bluefruit_event_handlers *handlers, uint8_t *data);
void handle_gyroscope_raw(bluefruit_event_handlers *handlers, uint8_t *data);

const size_t bluefruit_controller_num_commands = 2;
const bluefruit_controller_command bluefruit_controller_commands[] =
{
		// Control pad buttons (button and status)
		{ 'B', 2, handle_buttons_raw },
		// Gyroscope (three floats)
		{ 'G', 12, handle_gyroscope_raw },
};

static int bluefruit_controller_command_query(uint8_t shortcut,
		size_t *num_data_bytes, void (**handler)(bluefruit_event_handlers *handlers, uint8_t *))
{
	for (size_t i = 0; i < bluefruit_controller_num_commands; i++)
	{
		if (bluefruit_controller_commands[i].shortcut == shortcut)
		{
			*num_data_bytes = bluefruit_controller_commands[i].num_data_bytes;
			*handler = bluefruit_controller_commands[i].handler;
			return 0;
		}
	}
	return -1;
}

static const size_t bluefruit_controller_max_bytes_per_update = 5;



static void bluefruit_controller_status_reset(bluefruit_controller_status *status)
{
	status->state = BLUEFRUIT_CONTROLLER_STATE_SKIP;
	memset(status->buffer, BLUEFRUIT_CONTROLLER_BUF_NUMBYTES, sizeof(uint8_t));
	status->buffer_num_bytes = 0;
	status->num_data_bytes = 0;
	status->handler = NULL;
}



static void bluefruit_controller_status_add_byte(bluefruit_controller_status *status, uint8_t value)
{
	if (status->buffer_num_bytes >= BLUEFRUIT_CONTROLLER_BUF_NUMBYTES)
	{
		DEBUG_LOG("Bluefruit controller: Buffer size (%i) exceeded\n",
				BLUEFRUIT_CONTROLLER_BUF_NUMBYTES);
		while (1);
	}
	status->buffer[status->buffer_num_bytes] = value;
	status->buffer_num_bytes++;
}



static int bluefruit_controller_status_crc_okay(bluefruit_controller_status *status)
{
	// Calculate sum over all bytes in buffer except CRC
	uint8_t sum = 0;
	for (int i = 0; i < (status->buffer_num_bytes - 1); i++)
	{
		sum += status->buffer[i];
	}
	// CRC must match the bitwise inverse of the sum
	uint8_t crc = status->buffer[status->buffer_num_bytes - 1];
	return crc == (~sum & 0xff);
}



static void bluefruit_event_handlers_reset(bluefruit_event_handlers *handlers)
{
	handlers->handle_buttons = NULL;
	handlers->handle_gyroscope = NULL;
}



void bluefruit_controller_init(bluefruit_controller *ctrl, UART_HandleTypeDef *huart)
{
	ctrl->huart = huart;
	bluefruit_controller_status_reset(&ctrl->status);
	bluefruit_event_handlers_reset(&ctrl->handlers);
}



static void bluefruit_controller_update_byte(bluefruit_controller *ctrl, uint8_t value)
{
	//DEBUG_LOG("Controller status update: State %i, value %c (%02x)\n", ctrl->status.state, value, value);
	switch (ctrl->status.state)
	{
		case BLUEFRUIT_CONTROLLER_STATE_SKIP:
		{
			if (value == '!')
			{
				bluefruit_controller_status_reset(&ctrl->status);
				bluefruit_controller_status_add_byte(&ctrl->status, value);
				ctrl->status.state = BLUEFRUIT_CONTROLLER_STATE_COMMAND;
			}
			break;
		}
		case BLUEFRUIT_CONTROLLER_STATE_COMMAND:
		{
			// Get number of data bytes and handler for current command
			int ret = bluefruit_controller_command_query(value,
					&ctrl->status.num_data_bytes, &ctrl->status.handler);
			if (ret == -1)
			{
				DEBUG_LOG("Bluefruit controller: Unknown command '%c' (%02x)\r\n", value, value);
				ctrl->status.state = BLUEFRUIT_CONTROLLER_STATE_SKIP;
			}
			else
			{
				bluefruit_controller_status_add_byte(&ctrl->status, value);
				ctrl->status.state = BLUEFRUIT_CONTROLLER_STATE_DATA;
			}
			break;
		}
		case BLUEFRUIT_CONTROLLER_STATE_DATA:
		{
			bluefruit_controller_status_add_byte(&ctrl->status, value);
			// Buffer already contains '!' and command byte
			if (ctrl->status.buffer_num_bytes == (ctrl->status.num_data_bytes + 2))
			{
				ctrl->status.state = BLUEFRUIT_CONTROLLER_STATE_CRC;
			}
			break;
		}
		case BLUEFRUIT_CONTROLLER_STATE_CRC:
		{
			bluefruit_controller_status_add_byte(&ctrl->status, value);
			if (bluefruit_controller_status_crc_okay(&ctrl->status))
			{
				ctrl->status.handler(&ctrl->handlers, &ctrl->status.buffer[2]);
			}
			else
			{
				DEBUG_LOG("Bluefruit controller: CRC error\n", NULL);
			}
			ctrl->status.state = BLUEFRUIT_CONTROLLER_STATE_SKIP;
			break;
		}
	}
}



void bluefruit_controller_update(bluefruit_controller *ctrl)
{
	if(rxIntCount)
	{
		for (size_t i = 0; i < bluefruit_controller_max_bytes_per_update; i++)
		{
			//uint8_t value;
			//const uint32_t timeoutMilliseconds = 0;
			//HAL_StatusTypeDef retval = HAL_UART_Receive(ctrl->huart, &value,
					//1, timeoutMilliseconds);
			//if (retval == HAL_OK)
			//{
	//			DEBUG_LOG("Data: %c (%02x)\n", value, value);
				//bluefruit_controller_update_byte(ctrl, value);
				bluefruit_controller_update_byte(ctrl, RxBuf[i]);
			//}
		}
		rxIntCount = 0;
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1, RxBuf, 10);

	}

}



void handle_buttons_raw(bluefruit_event_handlers *handlers, uint8_t *data)
{
	int number = data[0] - '0';
	int is_pressed = data[1] - '0';
	if (handlers->handle_buttons != NULL)
	{
		handlers->handle_buttons(number, is_pressed);
	}
}



void handle_gyroscope_raw(bluefruit_event_handlers *handlers, uint8_t *data)
{
	float x = *((float *)&data[0]);
	float y = *((float *)&data[4]);
	float z = *((float *)&data[8]);
	if (handlers->handle_gyroscope != NULL)
	{
		handlers->handle_gyroscope(x, y, z);
	}
}

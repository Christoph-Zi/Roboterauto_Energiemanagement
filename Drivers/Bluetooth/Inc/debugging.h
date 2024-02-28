#ifndef INC_DEBUGGING_H_
#define INC_DEBUGGING_H_



#include "stm32f4xx_hal.h"



#define DEBUG_LOG_ENABLED
//#undef DEBUG_LOG_ENABLED



extern void debug_log(const char *format, ...);



#ifdef DEBUG_LOG_ENABLED
#define DEBUG_LOG(format, ...) debug_log(format, __VA_ARGS__)
//#define DEBUG_LOG(format, ...) debug_log(format, __VA_OPT__(,) __VA_ARGS__) // C++20
#else
#define DEBUG_LOG(format, ...)
#endif



#endif /* INC_DEBUGGING_H_ */

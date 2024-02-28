/*
 * ioExpander.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Jan Schuessler, FHGR
 */

#ifndef INC_IOEXPANDER_H_
#define INC_IOEXPANDER_H_


static const uint8_t LEDS_FL = 6; // The LEDS FL are connected to IO6
static const uint8_t LEDS_FR = 4; // The LEDS FR are connected to IO4
static const uint8_t LEDS_RL = 2; // The LEDS RL are connected to IO2
static const uint8_t LEDS_RR = 3; // The LEDS RR are connected to IO3
static const uint8_t B1 = 7; // User Button is connected to IO7

extern void ioExp_initPin(uint8_t input_output, uint8_t pin);
extern void ioExp_writePin(uint8_t high_low, uint8_t pin);
extern uint8_t ioExp_readPin(uint8_t pin);
extern uint8_t ioExp_readOutputs();
extern void ioExp_writeOutputs(uint8_t val);
extern void ioExp_init(void);
extern void toggleFrontLEDs(void);
extern void toggleRearLEDs(void);

#endif /* INC_IOEXPANDER_H_ */

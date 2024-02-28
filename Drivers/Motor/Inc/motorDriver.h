/*
 * motorDriver.h
 *
 *  Created on: 12.10.2021
 *      Author: catreggionpo
 */

#ifndef MOTOR_INC_MOTORDRIVER_H_
#define MOTOR_INC_MOTORDRIVER_H_

extern void setMotorSpeed(uint8_t speed, uint8_t dir);
extern void accelMotor(uint8_t speed, uint8_t dir);
extern void stopMotor(void);

#endif /* MOTOR_INC_MOTORDRIVER_H_ */

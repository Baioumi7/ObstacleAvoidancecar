/*
 * DcMotor_Interface.h
 *
 Author: BAYOUMII
 */

#ifndef HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../../MCAL/Timer_Driver/Timer_interface.h"

typedef enum {
	Speed_20P,
	Speed_30P,
	Speed_50P,
	Speed_70P,
	Speed_100P

}MotorSpeed;

void DcMotor_voidInit(void);
void Dc_Motor_voidSetSpeed(MotorSpeed M_Speed);
void DcMotor_voidForword();
void DcMotor_voidBackword();
void DcMotor_voidRotateRight();
void DcMotor_voidRotateLeft();


#endif /* HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_ */

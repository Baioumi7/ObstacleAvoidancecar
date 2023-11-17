/*
 * Interface.h
 *
 *  Created on: Jun 26, 2023
 *      Author: Kimo Store
 */

#ifndef ULTRASONICSENSOR_DRIVER_ULTRASONIC_INTERFACE_H_
#define ULTRASONICSENSOR_DRIVER_ULTRASONIC_INTERFACE_H_

#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../../MCAL/Timer_Driver/Timer_interface.h"
#include "../../MCAL/Ex_Interrupt_Driver/EXTI_Interface.h"

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

void Ultrasonic_voidInit(void);

void Ultrasonic_voidTrig(void);

u32 Ultrasonic_u32GettingDistance(void);

#endif /* ULTRASONICSENSOR_DRIVER_ULTRASONIC_INTERFACE_H_ */

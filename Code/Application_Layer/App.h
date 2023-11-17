/*
 * App.h
 *
 *  Created on: Jun 26, 2023
 *    Author: BAYOUMII
 */


#include "../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "../MCAL/Timer_Driver/Timer_interface.h"
#include "../HAL/Button_Driver/Btn_interface.h"
#include "../HAL/DCMotor_Driver/DcMotor_Interface.h"
#include "../HAL/LCD_Driver/LCD.h"
#include "../HAL/LED_Driver/LED_interface.h"
#include "../HAL/UltrasonicSensor_Driver/Ultrasonic_Interface.h"
#include "../SERVACE_LAYER/DATA_TYPES.h"
#include "../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#ifndef APP_H_
#define APP_H_

void App_Init(void);
void App_Start(void);

#endif /* APP_H_ */

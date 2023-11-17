/*
 * LED_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Kimo Store
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"


typedef enum
{
	LED_OK,
	LED_ERROR
}LED_State;

LED_State LED_voidInit(u8 Copy_u8Reg , u8 Copy_u8Pin);
LED_State LED_voidOn(u8 Copy_u8Reg , u8 Copy_u8Pin);
LED_State LED_voidOff(u8 Copy_u8Reg , u8 Copy_u8Pin);
LED_State LED_voidToggle(u8 Copy_u8Reg , u8 Copy_u8Pin);



#endif /* LED_INTERFACE_H_ */

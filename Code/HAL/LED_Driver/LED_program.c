/*
 * LED_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Kimo Store
 */

#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"


/*Skeleton
 * 1) it will take LED port and pin
 * 2) it will make this pin as output
 * 3) return ok or not ok
 * */
LED_State LED_voidInit(u8 Copy_u8Reg , u8 Copy_u8Pin)
{
	if(GPIO_void_Set_Direction_PIN(Copy_u8Reg , Copy_u8Pin , OUTPUT  ) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ERROR;
	}
}

/*Skeleton
 * 1) it will take LED port and pin
 * 2) it will put in this pin high 5v
 * 3) return ok or not ok
 * */
LED_State LED_voidOn(u8 Copy_u8Reg , u8 Copy_u8Pin)
{
	if(GPIO_void_Set_Value_PIN(Copy_u8Reg ,Copy_u8Pin , HIGH ) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ERROR;
	}
}

/*Skeleton
 * 1) it will take LED port and pin
 * 2) it will put in this pin low Ground 0v
 * 3) return ok or not ok
 * */

LED_State LED_voidOff(u8 Copy_u8Reg , u8 Copy_u8Pin)
{
	if(GPIO_void_Set_Value_PIN(Copy_u8Reg ,Copy_u8Pin , LOW ) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ERROR;
	}
}

/*Skeleton
 * 1) it will take LED port and pin
 * 2) it will toggle value of this pin if 0  to 1  and if 1 to 0
 * 3) return ok or not ok
 * */
LED_State LED_voidToggle(u8 Copy_u8Reg , u8 Copy_u8Pin)
{
	if(GPIO_void_Toggle_PIN(Copy_u8Reg ,Copy_u8Pin ) == GPIO_OK)
	{
		return LED_OK;
	}
	else
	{
		return LED_ERROR;
	}
}

/****************************************************** */
/* Author: BAYOUMII							*/

/****************************************************** */


#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#include "../../SERVACE_LAYER/DATA_TYPES.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"


typedef enum 
{
	EXTI_0,
	EXTI_1,
	EXTI_2	
}EXTI_TYPE;

typedef enum 
{	
	EXTI_LOW_LEVEL,
	EXTI_FALLING,
	EXTI_RISING,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_SENSE;


typedef enum
{
	ExI_OK,
	ExI_ERROR
}EXTI_State;


EXTI_State EXTI_voidEnable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE , EXTI_SENSE Copy_u8EXTI_Edge);

EXTI_State EXTI_voidDisable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE );

void EXTI_voidSET_CallBack(void(*FUN_CallBack)(void) , EXTI_TYPE Copy_u8EXTI_TYPE);

#endif

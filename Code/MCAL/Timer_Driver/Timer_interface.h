/*
 * Timer_interface.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_
#define MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "Timer_config.h"
typedef enum
{
	Timer0,
	Timer1,
	Timer2
}TimerType;

typedef enum
{
	Timer_OK,
	Timer_ERROR
}Timer_State;

typedef enum
{
	OVERFLOW_MODE,
	PWM_PHASE_CORRECR,
	OUT_COMPARE_MODE,
	FAST_PWM

}TimerMode;


#define toggleOC0 0
#define clearOC0  1
#define setOC0    2
#define OC0_Disconnected 3

#define toggleOC2 4
#define clearOC2  5
#define setOC2    6
#define OC2_Disconnected 7


#define toggleOC1A 8
#define clearOC1A 9
#define setOC1A 10
#define OC1A_Disconnected 11


#define toggleOC1B 12
#define clearOC1B 13
#define setOC1B 14
#define OC1B_Disconnected 15

#define T0_Inverting 0
#define T0_Noninverting 1

#define T2_Inverting 0
#define T2_Noninverting 1



Timer_State Timer_voidInit(TimerType Copy_EnumTimerType ,TimerMode Copy_EnumTimerMode );

Timer_State Timer_voidStart(TimerType Copy_EnumTimerType , u8 Copy_IntialValue);

Timer_State Timer_voidStop(TimerType Copy_EnumTimerType);

void Timer_voidClearCounter(TimerType Copy_EnumTimerType);

void Timer_voidSetCallBack(void (*copy_ISR)(void) ,TimerType Copy_enumTimerType ,  TimerMode Copy_enumTimerMode);

void Timer_SetDutyCycle(TimerType Copy_EnumTimerType , u16 DutyCycle);

void Timer1_EnableInputCaptureMode(ICU_Edge Edge);

void Timer1_WaitingRisingEdge(void);

void Timer1_WaitingFallingEdge(void);

u8 Timer1_GettingICU_Value(void);
u16 Timer_GettingCounter_Value(TimerType Copy_EnumTimerType);

#endif /* MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_ */

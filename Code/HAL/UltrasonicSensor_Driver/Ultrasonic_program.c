/*
 * program.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Kimo Store
 */

#include "Ultrasonic_Private.h"
#include "Ultrasonic_Interface.h"
#include "Ultrasonic_Config.h"
#include <util/delay.h>
#include "../../MCAL/Timer_Driver/Timer_config.h"


static u8 sensorWorking = 0;
static u8 risingEdge = 0;
static u8 timerConter = 0;
static u32 distance;


static void EXT0_ISR(void)
{

	if(sensorWorking == 1)
	{
		if(risingEdge == 0)
		{
			Timer_voidClearCounter(Timer0);
			risingEdge = 1;
			timerConter = 0;
		}
		else
		{

			distance=(timerConter*256+Timer_GettingCounter_Value(Timer0))/466;


			timerConter = 0;
			risingEdge = 0;
			sensorWorking = 0;
		}
	}
}

static void Timer_ISR(void)
{
	timerConter++;

}

void Ultrasonic_voidInit(void)
{
	GPIO_void_Set_Direction_PIN(Ult_TriggerPort , Ult_TriggerPin , OUTPUT);
	GPIO_void_Set_Direction_PIN(Ult_EchoPort , Ult_EchoPin , INPUT);
	GPIO_void_Set_PULL_UP(Ult_EchoPort , Ult_EchoPin);
	EXTI_voidEnable_EXTI(EXTI_0 ,EXTI_ANY_LOGICAL_CHANGE);
	EXTI_voidSET_CallBack(EXT0_ISR , EXTI_0);
	Timer_voidInit(Timer0 , OVERFLOW_MODE);
	Timer_voidSetCallBack(Timer_ISR , Timer0 , OVERFLOW_MODE);
	Timer_voidStart(Timer0 , 0);
}

void Ultrasonic_voidTrig(void)
{
	if(sensorWorking == 0)
	{
		GPIO_void_Set_Value_PIN(Ult_TriggerPort , Ult_TriggerPin , HIGH);
		_delay_us(20);
		GPIO_void_Set_Value_PIN(Ult_TriggerPort , Ult_TriggerPin , LOW);

		sensorWorking = 1;
	}

}

u32 Ultrasonic_u32GettingDistance(void)
{
	return distance;
}

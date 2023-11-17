/*
 * DcMotor_Program.c
 *
 Author: BAYOUMII
 */
#include "DcMotor_Private.h"
#include "DcMotor_Interface.h"
#include "DcMotor_Config.h"

void DcMotor_voidInit(void)
{
	Timer_voidInit(Timer2 , FAST_PWM);
	Timer_voidStart(Timer2 , 0);
	u8 index = 0;
	for(index = 0 ; index < 4;  index ++)
	{
		GPIO_void_Set_Direction_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin1 , OUTPUT);
		GPIO_void_Set_Direction_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin2 , OUTPUT);
	}
}

void Dc_Motor_voidSetSpeed(MotorSpeed M_Speed)
{
	switch(M_Speed)
	{
	case Speed_20P:
		Timer_SetDutyCycle(Timer2 , 51);
		break;
	case Speed_30P:
		Timer_SetDutyCycle(Timer2 ,76 );
		break;
	case Speed_50P:
		Timer_SetDutyCycle(Timer2 , 127);
		break;
	case Speed_70P:
		Timer_SetDutyCycle(Timer2 , 178);
		break;
	case Speed_100P:
		Timer_SetDutyCycle(Timer2 , 255);
		break;
	default:

		break;
	}
}
void DcMotor_voidForword()
{
	u8 index = 0;
	for(index = 0 ; index < MotorsNumber;  index ++)
	{
		GPIO_void_Set_Value_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin1 , HIGH);
		GPIO_void_Set_Value_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin2 , LOW);
	}
}
void DcMotor_voidBackword()
{
	u8 index = 0;
	for(index = 0 ; index < MotorsNumber;  index ++)
	{
		GPIO_void_Set_Value_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin1 , LOW);
		GPIO_void_Set_Value_PIN(M_arr[index].MotorPort , M_arr[index].MotorPin2 , HIGH);
	}
}
void DcMotor_voidRotateRight()
{
	DcMotor_voidForword();
	GPIO_void_Set_Value_PIN(GPIOA , PIN2 , LOW);// Stop Motor 2 to rotate right
}

void DcMotor_voidRotateLeft()
{
	DcMotor_voidForword();
	GPIO_void_Set_Value_PIN(GPIOA , PIN6 , LOW);// Stop Motor 4 to rotate left
}

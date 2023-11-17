/*
 * App.c
 *
 *  Created on: Jun 26, 2023
 *    Author: BAYOUMII
 */
#include "App.h"

volatile u32 T1_CounterOverflow = 0;
volatile u32 T1_Flag = 0;
f32 Distance;
u8 DistanceArr[10];

u8 BtnState = 0; // Right Direction is Default


void Timer1ISR2()
{
	T1_Flag++;
}

void Timer1ISR(void)
{
	T1_CounterOverflow++;
	if(T1_CounterOverflow == 15 )
	{
		//LED_voidToggle(GPIOC , PIN2);
	}
	else if(T1_CounterOverflow == 30 )
	{


	}else if(T1_CounterOverflow == 75)
	{
		LCD_Clear_Display();
		LCD_Send_String_Row_Column(0,0,"Starting Program");
	}
	else if(T1_CounterOverflow == 105 )
	{
		LCD_Clear_Display();
	}

}

void App_Init(void)
{

	Timer_voidInit(Timer1 , OVERFLOW_MODE);
	Timer_voidStart(Timer1 , 0);
	Timer_voidSetCallBack(Timer1ISR , Timer1 , OVERFLOW_MODE);

	DcMotor_voidInit();
	LCD_Init();
	Btn_voidInitPullUpOn(GPIOC , PIN3);


	LED_voidInit(GPIOC , PIN2);
	LED_voidOn(GPIOC , PIN2);

	Ultrasonic_voidInit();

	LCD_Clear_Display();
	LCD_Send_String_Row_Column(0,0,"Enter Rotate Dir");
	LCD_Send_String_Row_Column(1,0,"Direction->Right");

}
void App_Start(void)
{
	while(boolTrue)
	{
		if(T1_CounterOverflow < 75)
		{
			if(Btn_voidRead(GPIOC , PIN3) == 0)
			{
				if(BtnState == 0)
				{
					BtnState = 1;
					LCD_Send_String_Row_Column(1,11,"Left ");
				}
				else
				{
					BtnState = 0;
					LCD_Send_String_Row_Column(1,11,"Right");
				}
				LED_voidToggle(GPIOC , PIN2);
				_delay_ms(200);
			}
		}
		if(T1_CounterOverflow > 105)
		{
			Timer_voidStop(Timer1);
			Ultrasonic_voidTrig();
			Distance = Ultrasonic_u32GettingDistance();
			LCD_intToStr(Distance , (char*)DistanceArr , 3);


			LCD_Send_String_Row_Column(0,0,"Speed:");
			LCD_Send_String_Row_Column(0,10,"Dir:");
			LCD_Send_String_Row_Column(1,0,"Dist.:");
			LCD_Send_String_Row_Column(1,10 , "cm");
			LCD_Send_String_Row_Column(1,6,(char *)DistanceArr);


			if(Distance > 70)
			{
				Dc_Motor_voidSetSpeed(Speed_30P);
				LCD_Send_String_Row_Column(0,6,"30%");
				LCD_Send_String_Row_Column(0,14,"F ");
				DcMotor_voidForword();

				Timer_voidSetCallBack(Timer1ISR2 , Timer1 , OVERFLOW_MODE);
				Timer_voidStart(Timer1 , 0);
				while(T1_Flag < 75){}
				while(Distance > 70 )
				{
					Timer_voidStop(Timer1);
					T1_Flag = 0;
					Dc_Motor_voidSetSpeed(Speed_50P);
					LCD_Send_String_Row_Column(0,6,"50%");
					Ultrasonic_voidTrig();
					Distance = Ultrasonic_u32GettingDistance();
					LCD_intToStr(Distance , (char *)DistanceArr , 3);
					LCD_Send_String_Row_Column(1,6, (char*)DistanceArr);
				}

			}
			else if(Distance > 30 && Distance < 70)
			{
				Dc_Motor_voidSetSpeed(Speed_30P);
				LCD_Send_String_Row_Column(0,6,"30%");
				LCD_Send_String_Row_Column(0,14,"F ");
				DcMotor_voidForword();
			}else if(Distance > 20 && Distance < 30)
			{
				if(BtnState == 0)
				{
					DcMotor_voidRotateRight();
					LCD_Send_String_Row_Column(0,14,"RR");
				}
				else
				{
					DcMotor_voidRotateLeft();
					LCD_Send_String_Row_Column(0,14,"RL");
				}
			}
			else if(Distance < 20)
			{
				Dc_Motor_voidSetSpeed(Speed_30P);
				LCD_Send_String_Row_Column(0,6,"30%");
				LCD_Send_String_Row_Column(0,14,"B ");
				DcMotor_voidBackword();
			}
			else
			{

			}

		}

	}

}


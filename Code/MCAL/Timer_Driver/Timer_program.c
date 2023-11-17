/*
 * Timer_program.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Kimo Store
 */

#include "Timer_private.h"
#include "Timer_interface.h"
#include "Timer_config.h"


static void (*Timer0_CallBack[2])(void) = {NULL};
static void (*Timer2_CallBack[2])(void) = {NULL};
static void (*Timer1_CallBack[3])(void) = {NULL};

ISR(TIMER0_OVERFLOW_VECTOR)
{
	Timer0_CallBack[0]();
}

ISR(TIMER0_OUTCOMP_VECTOR)
{
	Timer0_CallBack[1]();
}


ISR(TIMER2_OVERFLOW_VECTOR)
{
	Timer2_CallBack[0]();
}

ISR(TIMER2_OUTCOMP_VECTOR)
{
	Timer2_CallBack[1]();
}



ISR(TIMER1_OVERFLOW_VECTOR)
{
	Timer1_CallBack[0]();
}
ISR(TIMER1_OUTCOMPA_VECTOR)
{
	Timer1_CallBack[1]();
}
ISR(TIMER1_OUTCOMPB_VECTOR)
{
	Timer1_CallBack[2]();
}

Timer_State Timer_voidInit(TimerType Copy_EnumTimerType ,TimerMode Copy_EnumTimerMode )
{
	sei();
	Timer_State state = Timer_ERROR;
	switch(Copy_EnumTimerMode)
	{
	case OVERFLOW_MODE:
		switch(Copy_EnumTimerType)
		{
		case Timer0:

			CLEAR_BIT(TCCR0 ,WGM00 );
			CLEAR_BIT(TCCR0 ,WGM01 );
			SET_BIT(TIMSK , TOIE0);
			state = Timer_OK;

			break;


		case Timer1:
			CLEAR_BIT(TCCR1A ,WGM10 );
			CLEAR_BIT(TCCR1A ,WGM11 );
			CLEAR_BIT(TCCR1B ,WGM12 );
			CLEAR_BIT(TCCR1B ,WGM13 );
			SET_BIT(TIMSK , TOIE1);

			state = Timer_OK;
			break;

		case Timer2:
			CLEAR_BIT(TCCR2 ,WGM20 );
			CLEAR_BIT(TCCR2 ,WGM21 );
			SET_BIT(TIMSK , TOIE2);
			state = Timer_OK;
			break;
		default:
			state = Timer_ERROR;
			break;
		}
		break;


		case OUT_COMPARE_MODE:
			switch(Copy_EnumTimerType)
			{
			case Timer0:
				CLEAR_BIT(TCCR0 ,WGM00 );
				SET_BIT(TCCR0 ,WGM01 );
				SET_BIT(TIMSK , OCIE0);

#if OCO_Response == OC0_Disconnected
				CLEAR_BIT(TCCR0 ,COM00 );
				CLEAR_BIT(TCCR0 ,COM01 );
#elif OCO_Response == toggleOC0
				SET_BIT(TCCR0 ,COM00 );
				CLEAR_BIT(TCCR0 ,COM01 );
#elif OCO_Response == clearOC0
				CLEAR_BIT(TCCR0 ,COM00 );
				SET_BIT(TCCR0 ,COM01 );
#elif OCO_Response == setOC0
				SET_BIT(TCCR0 ,COM00 );
				SET_BIT(TCCR0 ,COM01 );
#endif
				state = Timer_OK;
				break;

			case Timer1:
				CLEAR_BIT(TCCR1A ,WGM10 );
				CLEAR_BIT(TCCR1A ,WGM11 );
				SET_BIT(TCCR1B ,WGM12 );
				CLEAR_BIT(TCCR1B ,WGM13 );
				SET_BIT(TIMSK , OCIE1A);
				SET_BIT(TIMSK , OCIE1B);

#if OC1A_Response == OC1A_Disconnected
				CLEAR_BIT(TCCR1A , COM1A0);
				CLEAR_BIT(TCCR1A , COM1A1);
#elif OC1A_Response == setOC1A
				SET_BIT(TCCR1A , COM1A0);
				SET_BIT(TCCR1A , COM1A1);
#elif OC1A_Response == clearOC1A
				CLEAR_BIT(TCCR1A , COM1A0);
				SET_BIT(TCCR1A , COM1A1);
#elif OC1A_Response == toggleOC1A
				SET_BIT(TCCR1A , COM1A0);
				CLEAR_BIT(TCCR1A , COM1A1);
#endif
#if OC1B_Response == OC1B_Disconnected
				CLEAR_BIT(TCCR1A , COM1B0);
				CLEAR_BIT(TCCR1A , COM1B1);
#elif OC1B_Response == setOC1B
				SET_BIT(TCCR1A , COM1B0);
				SET_BIT(TCCR1A , COM1B1);
#elif OC1B_Response == clearOC1B
				CLEAR_BIT(TCCR1A , COM1B0);
				SET_BIT(TCCR1A , COM1B1);
#elif OC1B_Response == toggleOC1B
				SET_BIT(TCCR1A , COM1B0);
				CLEAR_BIT(TCCR1A , COM1B1);
#endif

				break;

			case Timer2:
				CLEAR_BIT(TCCR2 ,WGM20 );
				SET_BIT(TCCR2 ,WGM21 );
				SET_BIT(TIMSK , OCIE2);

#if OC2_Response == OC2_Disconnected
				CLEAR_BIT(TCCR2 ,COM20 );
				CLEAR_BIT(TCCR2 ,COM21 );
#elif OC2_Response == toggleOC2
				SET_BIT(TCCR2 ,COM20 );
				CLEAR_BIT(TCCR2 ,COM21 );
#elif OC2_Response == clearOC2
				CLEAR_BIT(TCCR2 ,COM20 );
				SET_BIT(TCCR2 ,COM21 );
#elif OC2_Response == setOC2
				SET_BIT(TCCR2 ,COM20 );
				SET_BIT(TCCR2 ,COM21 );
#endif

				state = Timer_OK;
				break;
			default:
				state = Timer_ERROR;
				break;
			}


			break;

			case PWM_PHASE_CORRECR:

				switch(Copy_EnumTimerType)
				{
				case Timer0:
					SET_BIT(TCCR0 ,WGM00 );
					CLEAR_BIT(TCCR0 ,WGM01 );
					break;


				case Timer1:


					break;


				case Timer2:

					SET_BIT(TCCR2 ,WGM20 );
					CLEAR_BIT(TCCR2 ,WGM21 );

					break;
				default:
					state = Timer_ERROR;
					break;
				}

				break;

				case FAST_PWM:

					switch(Copy_EnumTimerType)
					{
					case Timer0:

						SET_BIT(TCCR0 ,WGM00 );
						SET_BIT(TCCR0 ,WGM01 );

#if FastPwmModeTimer0 == T0_Inverting
						SET_BIT(TCCR0 ,COM00 );
						SET_BIT(TCCR0 ,COM01 );
#elif FastPwmModeTimer0 == T0_Noninverting
						CLEAR_BIT(TCCR0 ,COM00 );
						SET_BIT(TCCR0 ,COM01 );
#endif
						GPIO_void_Set_Direction_PIN(GPIOB , PIN3 , OUTPUT);


						OCR0 = 0;

						break;


					case Timer1:


						break;


					case Timer2:
						SET_BIT(TCCR2 ,WGM20 );
						SET_BIT(TCCR2 ,WGM21 );

#if FastPwmModeTimer2 == T2_Inverting

						SET_BIT(TCCR2 ,COM20 );
						SET_BIT(TCCR2 ,COM21 );
#elif FastPwmModeTimer2 == T2_Noninverting
						CLEAR_BIT(TCCR2 ,COM20 );
						SET_BIT(TCCR2 ,COM21 );
#endif
						GPIO_void_Set_Direction_PIN(GPIOD , PIN7 , OUTPUT);


						OCR2 = 0;

						break;

						break;
					default:
						state = Timer_ERROR;
						break;
					}

					break;
					default:
						state = Timer_ERROR;
						break;
	}

	return state;
}

Timer_State Timer_voidStart(TimerType Copy_EnumTimerType , u8 Copy_IntialValue)
{
	u8 state = Timer_ERROR;
	switch(Copy_EnumTimerType)
	{
	case Timer0:

		TCNT0 = Copy_IntialValue;
#if Timer0_Prescaler == 1
		SET_BIT(TCCR0 ,CS00 );
		CLEAR_BIT(TCCR0 ,CS01);
		CLEAR_BIT(TCCR0 ,CS02);
#elif Timer0_Prescaler == 8
		CLEAR_BIT(TCCR0 ,CS00 );
		SET_BIT(TCCR0 ,CS01);
		CLEAR_BIT(TCCR0 ,CS02);
#elif Timer0_Prescaler == 64
		SET_BIT(TCCR0 ,CS00 );
		SET_BIT(TCCR0 ,CS01);
		CLEAR_BIT(TCCR0 ,CS02);
#elif Timer0_Prescaler == 256
		CLEAR_BIT(TCCR0 ,CS00 );
		CLEAR_BIT(TCCR0 ,CS01);
		SET_BIT(TCCR0 ,CS02);
#elif Timer0_Prescaler == 1024
		SET_BIT(TCCR0 ,CS00 );
		CLEAR_BIT(TCCR0 ,CS01);
		SET_BIT(TCCR0 ,CS02);
#endif

		state = Timer_OK;

		break;
	case Timer1:
		TCNT1 = Copy_IntialValue;
#if Timer1_Prescaler == 1
		SET_BIT(TCCR1B ,CS10 );
		CLEAR_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
#elif Timer1_Prescaler == 8
		CLEAR_BIT(TCCR1B ,CS10 );
		SET_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
#elif Timer1_Prescaler == 64
		SET_BIT(TCCR1B ,CS10 );
		SET_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);
#elif Timer1_Prescaler == 256
		CLEAR_BIT(TCCR1B ,CS10 );
		CLEAR_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);
#elif Timer1_Prescaler == 1024
		SET_BIT(TCCR1B ,CS10 );
		CLEAR_BIT(TCCR1B ,CS11);
		SET_BIT(TCCR1B ,CS12);
#endif
		break;

	case Timer2:
		TCNT2 = Copy_IntialValue;
#if Timer2_Prescaler == 1
		SET_BIT(TCCR2 ,CS20 );
		CLEAR_BIT(TCCR2 ,CS21);
		CLEAR_BIT(TCCR2 ,CS22);
#elif Timer2_Prescaler == 8
		CLEAR_BIT(TCCR2 ,CS20 );
		SET_BIT(TCCR2 ,CS21);
		CLEAR_BIT(TCCR2 ,CS22);
#elif Timer2_Prescaler == 64
		SET_BIT(TCCR2 ,CS20 );
		SET_BIT(TCCR2 ,CS21);
		CLEAR_BIT(TCCR2 ,CS22);
#elif Timer2_Prescaler == 256
		CLEAR_BIT(TCCR2 ,CS20 );
		CLEAR_BIT(TCCR2 ,CS21);
		SET_BIT(TCCR2 ,CS22);
#elif Timer2_Prescaler == 1024
		SET_BIT(TCCR2 ,CS20 );
		CLEAR_BIT(TCCR2 ,CS21);
		SET_BIT(TCCR2 ,CS22);
#endif
		state = Timer_OK;
		break;
	default:
		state = Timer_ERROR;
		break;
	}
	return state;

}

Timer_State Timer_voidStop(TimerType Copy_EnumTimerType)
{
	u8 state = Timer_ERROR;
	switch(Copy_EnumTimerType)
	{
	case Timer0:
		TCNT0 = 0;
		CLEAR_BIT(TCCR0 ,CS00 );
		CLEAR_BIT(TCCR0 ,CS01);
		CLEAR_BIT(TCCR0 ,CS02);

		state = Timer_OK;

		break;
	case Timer1:

		TCNT1 = 0;
		CLEAR_BIT(TCCR1B ,CS10 );
		CLEAR_BIT(TCCR1B ,CS11);
		CLEAR_BIT(TCCR1B ,CS12);

		break;

	case Timer2:
		TCNT2 = 0;
		CLEAR_BIT(TCCR2 ,CS20 );
		CLEAR_BIT(TCCR2 ,CS21);
		CLEAR_BIT(TCCR2 ,CS22);

		state = Timer_OK;
		break;
	default:
		state = Timer_ERROR;
		break;
	}
	return state;
}

void Timer_voidSetCallBack(void (*copy_ISR)(void) ,TimerType Copy_enumTimerType ,  TimerMode Copy_enumTimerMode)
{
	switch(Copy_enumTimerType)
	{
	case Timer0:

		switch(Copy_enumTimerMode)
		{
		case OVERFLOW_MODE:
			Timer0_CallBack[0] = copy_ISR;
			break;
		case OUT_COMPARE_MODE:
			Timer0_CallBack[1] = copy_ISR;
			break;

		case PWM_PHASE_CORRECR:


			break;


		case FAST_PWM:


			break;
		}
		break;
		case Timer1:
			switch(Copy_enumTimerMode)
			{
			case OVERFLOW_MODE:
				Timer1_CallBack[0] = copy_ISR;
				break;
			case OUT_COMPARE_MODE:
				if(Timer1OutCompareA == 1)
					Timer1_CallBack[1] = copy_ISR;
				if( Timer1OutCompareB == 1)
					Timer1_CallBack[2] = copy_ISR;
				break;

			case PWM_PHASE_CORRECR:


				break;


			case FAST_PWM:


				break;
			}

			break;



			case Timer2:
				switch(Copy_enumTimerMode)
				{
				case OVERFLOW_MODE:
					Timer2_CallBack[0] = copy_ISR;
					break;
				case OUT_COMPARE_MODE:
					Timer2_CallBack[1] = copy_ISR;
					break;

				case PWM_PHASE_CORRECR:


					break;


				case FAST_PWM:


					break;
				}

				break;
	}
}
void Timer_SetDutyCycle(TimerType Copy_EnumTimerType , u16 DutyCycle)
{
	switch(Copy_EnumTimerType)
	{
	case Timer0:
		OCR0 = (u8)DutyCycle;
		break;
	case Timer1:
		OCR1A = DutyCycle;
		break;
	case Timer2:
		OCR2 = (u8)DutyCycle;
		break;
	}
}
void Timer1_EnableInputCaptureMode(ICU_Edge Edge)
{

	TCNT1 = 0;
	/*
	switch(Edge)
	{
	case ICU_Rising:
		SET_BIT(TCCR1B , ICES1);
		break;
	case ICU_Falling:
		CLEAR_BIT(TCCR1B , ICES1);
		break;
	default:
		break;
	}

	SET_BIT(TIFR , ICF1);
	SET_BIT(TIFR , TOV1);
	 */
	TCCR1B = 0x41;
	TIFR = 1<<ICF1;
	TIFR = 1<<TOV1;
}
void Timer1_WaitingRisingEdge(void)
{
	while((TIFR & (1<<ICF1)) == 0);
	TCNT1 = 0;
	/*
	CLEAR_BIT(TCCR1B , ICES1); // Falling
	SET_BIT(TIFR , ICF1);
	SET_BIT(TIFR , TOV1);
	 */
	TCCR1B = 0x01;
	TIFR = 1<<ICF1;
	TIFR = 1<<TOV1;
}
void Timer1_WaitingFallingEdge(void)
{
	while((TIFR & (1<<ICF1)) == 0);
}

u8 Timer1_GettingICU_Value()
{
	return ICR1;
}
void Timer_voidClearCounter(TimerType Copy_EnumTimerType)
{
	switch(Copy_EnumTimerType)
	{
	case Timer0:
		TCNT0 = 0x00;
		break;
	case Timer1:
		TCNT1 = 0x00;
		break;
	case Timer2:
		TCNT2 = 0x00;
		break;
	}

}

u16 Timer_GettingCounter_Value(TimerType Copy_EnumTimerType)
{
	u16 retVal = 0;
	switch(Copy_EnumTimerType)
	{
	case Timer0:
		retVal = TCNT0;
		break;
	case Timer1:
		retVal = TCNT1;
		break;
	case Timer2:
		retVal = TCNT2;
		break;
	}
	return retVal;
}

/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"

static void (*EXTI_CallBack[3])(void) = {NULL};

ISR(EXTI0_VECTOR)
{
	EXTI_CallBack[0]();
}

ISR(EXTI1_VECTOR)
{
	EXTI_CallBack[1]();
}

ISR(EXTI2_VECTOR)
{
	EXTI_CallBack[2]();
}

/*Skeleton
 * 1) This Function will take wanted Type of Interrupt( EXINT0 , EXINT1 , EXINT2 ) and Interrupt Sense (Falling , Rising , AnyChange , LOW Level)
 * 2) it will return OK or Not OK
 * 3) it will Enable wanted Interrupt with wanted Sense ...
 * */


EXTI_State EXTI_voidEnable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE , EXTI_SENSE Copy_u8EXTI_Edge)
{

	sei();
	u8 state = ExI_OK;
	switch(Copy_u8EXTI_TYPE)
	{
	case EXTI_0:
		SET_BIT(GICR , INT0);
		switch(Copy_u8EXTI_Edge)
		{
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR ,ISC00);
			CLEAR_BIT(MCUCR ,ISC01);
			break;
		case EXTI_FALLING:
			CLEAR_BIT(MCUCR ,ISC00);
			SET_BIT(MCUCR ,ISC01);
			break;
		case EXTI_RISING:
			SET_BIT(MCUCR ,ISC00);
			SET_BIT(MCUCR ,ISC01);
			break;
		case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR ,ISC00);
			CLEAR_BIT(MCUCR ,ISC01);
			break;
		default:
			state = ExI_ERROR;
			break;
		}
		break;
		case EXTI_1:
			SET_BIT(GICR , INT1);
			switch(Copy_u8EXTI_Edge)
			{
			case EXTI_LOW_LEVEL:
				CLEAR_BIT(MCUCR ,ISC10);
				CLEAR_BIT(MCUCR ,ISC11);
				break;
			case EXTI_FALLING:
				CLEAR_BIT(MCUCR ,ISC10);
				SET_BIT(MCUCR ,ISC11);
				break;
			case EXTI_RISING:
				SET_BIT(MCUCR ,ISC10);
				SET_BIT(MCUCR ,ISC11);
				break;
			case EXTI_ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR ,ISC10);
				CLEAR_BIT(MCUCR ,ISC11);
				break;
			default:
				state = ExI_ERROR;
				break;
			}
			break;
			case EXTI_2:
				SET_BIT(GICR , INT2);
				switch(Copy_u8EXTI_Edge)
				{
				case EXTI_FALLING:
					CLEAR_BIT(MCUCSR ,ISC2);
					break;
				case EXTI_RISING:
					SET_BIT(MCUCSR ,ISC2);
					break;
				default:
					state = ExI_ERROR;
					break;
				}
				break;
				default:
					state = ExI_ERROR;
					break;
	}

	return state;

}

/*Skeleton
 * 1) This Function will take wanted Type of Interrupt( EXINT0 , EXINT1 , EXINT2 )
 * 2) it will return OK or Not OK
 * 3) it will Disable wanted Interrupt with wanted Sense ...
 * */
EXTI_State EXTI_voidDisable_EXTI(EXTI_TYPE Copy_u8EXTI_TYPE)
{
	u8 state = ExI_OK;
	switch(Copy_u8EXTI_TYPE)
	{
	case EXTI_0:
		CLEAR_BIT(GICR , INT0);
		break;
	case EXTI_1:
		CLEAR_BIT(GICR , INT1);
		break;
	case EXTI_2:
		CLEAR_BIT(GICR , INT2);
		break;
	default:
		state = ExI_ERROR;
		break;
	}
	return state;
}


/*Skeleton
 * This function will take Function which i want to execute when interrupt come and push it into ISR in External Interrupt Driver
 * */
void EXTI_voidSET_CallBack(void(*FUN_CallBack)(void) , EXTI_TYPE Copy_u8EXTI_TYPE)
{
	EXTI_CallBack[Copy_u8EXTI_TYPE] = FUN_CallBack;

}



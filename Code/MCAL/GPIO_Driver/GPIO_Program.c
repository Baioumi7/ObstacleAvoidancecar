/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */
#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

/* REG : GPIOA , GPIOB , GPIOC or GPIOD */


/*Skeleton
 * 1) This Function will take wanted port and pin and the mode(output or input ) which user want it
 * 2) it will return GPIO_OK or GPIO_ERROR
 * 3) it will check and set or clear pins in DDRx which responsible for Direction of data for all pins in all ports which x is (A , B , C , D)
 * */
GPIO_STATE GPIO_void_Set_Direction_PIN(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8MODE)
{
	GPIO_STATE state = GPIO_ERROR;
	if(Copy_u8MODE == OUTPUT)
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			SET_BIT(DDRA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			SET_BIT(DDRB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			SET_BIT(DDRC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			SET_BIT(DDRD , Copy_u8PIN);
			break;
		}
		default:
			state = GPIO_ERROR;
			break;
		}
	}
	else if (Copy_u8MODE ==  INPUT)
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			CLEAR_BIT(DDRA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			CLEAR_BIT(DDRB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			CLEAR_BIT(DDRC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			CLEAR_BIT(DDRD , Copy_u8PIN);
			break;
		}
		default :
			state = GPIO_ERROR;
			break;
		}

	}
	else
	{
		state = GPIO_ERROR;
	}

	return state;
}
/*Skeleton
 * 1) This Function will take wanted port and pin and the Value (High 5V or Low GND ) which user want it for this pin
 * 2) it will return GPIO_OK or GPIO_ERROR
 * 3) it will check and set or clear pins in PORTx which responsible for the value of data for all pins in all ports which x is (A , B , C , D)
 * */
GPIO_STATE GPIO_void_Set_Value_PIN(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8VALUE)
{
	GPIO_STATE state = GPIO_ERROR;

	if(Copy_u8VALUE == HIGH)
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			SET_BIT(PORTA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			SET_BIT(PORTB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			SET_BIT(PORTC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			SET_BIT(PORTD , Copy_u8PIN);
			break;
		}
		default:
			state = GPIO_ERROR;
		}
	}
	else if (Copy_u8VALUE == LOW)
	{
		switch(Copy_u8REG)
		{
		case GPIOA:
		{
			CLEAR_BIT(PORTA , Copy_u8PIN);
			break;
		}
		case GPIOB:
		{
			CLEAR_BIT(PORTB , Copy_u8PIN);
			break;
		}
		case GPIOC:
		{
			CLEAR_BIT(PORTC , Copy_u8PIN);
			break;
		}
		case GPIOD:
		{
			CLEAR_BIT(PORTD , Copy_u8PIN);
			break;
		}
		default:
			state = GPIO_ERROR;
			break;
		}
	}

	else
	{
		state = GPIO_ERROR;
	}

	return state;
}
/*Skeleton
 * 1) This Function will take wanted port and pin
 * 2) it will return GPIO_OK or GPIO_ERROR
 * 3) it will check and set or clear pins in PORTx which responsible for PULL UP Resistor for input pins in all ports which x is (A , B , C , D)
 * */
GPIO_STATE GPIO_void_Set_PULL_UP(u8 Copy_u8REG , u8 Copy_u8PIN)
{
	GPIO_STATE state = GPIO_ERROR;
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		SET_BIT(PORTA , Copy_u8PIN);
		break;
	}
	case GPIOB:
	{
		SET_BIT(PORTB , Copy_u8PIN);
		break;
	}
	case GPIOC:
	{
		SET_BIT(PORTC , Copy_u8PIN);
		break;
	}
	case GPIOD:
	{
		SET_BIT(PORTD , Copy_u8PIN);
		break;
	}
	default:
		state = GPIO_ERROR;
		break;

	}

	return state;
}

/*Skeleton
 * 1) This Function will take wanted port and pin
 * 2) it will return GPIO_OK or GPIO_ERROR
 * 3) it will toggle the wanted pin if it 0 set to 1   or if it 1 set to 0  in PORTx which x is (A , B , C , D)
 * */
GPIO_STATE GPIO_void_Toggle_PIN(u8 Copy_u8REG , u8 Copy_u8PIN)
{
	GPIO_STATE state = GPIO_ERROR;
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		TOGGLE_BIT(PORTA , Copy_u8PIN);
		break;
	}
	case GPIOB:
	{
		TOGGLE_BIT(PORTB , Copy_u8PIN);
		break;
	}
	case GPIOC:
	{
		TOGGLE_BIT(PORTC , Copy_u8PIN);
		break;
	}
	case GPIOD:
	{
		TOGGLE_BIT(PORTD , Copy_u8PIN);
		break;
	}
	default:
		state = GPIO_ERROR;
		break;

	}

	return state;
}

/*Skeleton
 * 1) This Function will take wanted port and pin and the value of the pin if it 1  or 0
 * 2) it will return void beacause it will read pin
 * 3) it will take the value of pin and put it in variable to check in the main if the pin is 0 or  1
 * */
u8 GPIO_void_ReadPIN(u8 Copy_u8REG , u8 Copy_u8PIN )
{
	u8 state = 0;
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		if(!CHECK_BIT(PINA , Copy_u8PIN))
		{
			state =  0;
		}
		else
		{
			state = 1;
		}
		break;
	}
	case GPIOB:
	{
		if(!CHECK_BIT(PINB , Copy_u8PIN))
		{
			state = 0;
		}
		else
		{
			state = 1;
		}
		break;
	}
	case GPIOC:
	{
		if(!CHECK_BIT(PINC , Copy_u8PIN))
		{
			state = 0;
		}
		else
		{
			state = 1;
		}
		break;
	}
	case GPIOD:
	{
		if(!CHECK_BIT(PIND , Copy_u8PIN))
		{
			state = 0;
		}
		else
		{
			state = 1;
		}
		break;
	}

	}

	return state;
}

GPIO_STATE GPIO_void_SET_PORT_VALUE(u8 Copy_u8REG , u8 Copy_u8VALUE)
{
	GPIO_STATE state = GPIO_ERROR;
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		PORTA  =Copy_u8VALUE;
		break;
	}
	case GPIOB:
	{
		PORTB  =Copy_u8VALUE;
		break;
	}
	case GPIOC:
	{
		PORTC  =Copy_u8VALUE;
		break;
	}
	case GPIOD:
	{
		PORTD  =Copy_u8VALUE;
		break;
	}
	default:
		state = GPIO_ERROR;
		break;

	}

	return state;
}
GPIO_STATE GPIO_void_SET_PORT_DIR(u8 Copy_u8REG , u8 Copy_u8MODE)
{
	GPIO_STATE state = GPIO_ERROR;
	switch(Copy_u8REG)
	{
	case GPIOA:
	{
		if(Copy_u8MODE == OUTPUT)
		{
			DDRA = 0XFF;
		}else if( Copy_u8MODE == INPUT)
		{
			DDRA = 0x00;
		}
		break;
	}
	case GPIOB:
	{
		if(Copy_u8MODE == OUTPUT)
		{
			DDRB = 0xFF;
		}else if( Copy_u8MODE == INPUT)
		{
			DDRB = 0x00;
		}
		break;
	}
	case GPIOC:
	{
		if(Copy_u8MODE == OUTPUT)
		{
			DDRC = 0xFF;
		}else if( Copy_u8MODE == INPUT)
		{
			DDRC = 0x00;
		}
		break;
	}
	case GPIOD:
	{
		if(Copy_u8MODE == OUTPUT)
		{
			DDRD = 0xFF;
		}else if( Copy_u8MODE == INPUT)
		{
			DDRD = 0x00;
		}
		break;
	}
	default:
		state = GPIO_ERROR;
		break;

	}

	return state;
}

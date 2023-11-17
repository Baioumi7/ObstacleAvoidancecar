/****************************************************** */
/* Author: BAYOUMII							*/

/****************************************************** */


#include "Btn_interface.h"

/*Skeleton
 * 1) This Function will take Btn DDRx and pin and if you want pull up or not
 * 2) it will make this pin as output
 * 3) it will enable pull up resistor if the user need it
 * 4) it will return OK or NOT OK.
 * */
void Btn_voidInitPullUpOn(u8 Copy_u8Reg , u8 Copy_u8Pin)
{

	GPIO_void_Set_Direction_PIN(Copy_u8Reg , Copy_u8Pin , INPUT);
	GPIO_void_Set_Value_PIN(Copy_u8Reg , Copy_u8Pin , HIGH);

}
void Btn_voidInitPullUpOff(u8 Copy_u8Reg , u8 Copy_u8Pin)
{
	GPIO_void_Set_Direction_PIN(Copy_u8Reg , Copy_u8Pin , INPUT);
}

/*Skeleton
 * 1) this function will take wanted port and pin and will return if the button pressed or not
 * 2) it will return state of the button
 * */
u8 Btn_voidRead(u8 Copy_u8Reg ,  u8 Copy_u8Pin )
{
	u8 state;
	state = GPIO_void_ReadPIN(Copy_u8Reg ,Copy_u8Pin );

	return state;
}

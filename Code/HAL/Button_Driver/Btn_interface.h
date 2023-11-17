/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */

#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_


#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"

void Btn_voidInitPullUpOn(u8 Copy_u8Reg , u8 Copy_u8Pin);
void Btn_voidInitPullUpOff(u8 Copy_u8Reg , u8 Copy_u8Pin);
u8 Btn_voidRead(u8 Copy_u8Reg ,  u8 Copy_u8Pin );

#endif /* BTN_INTERFACE_H_ */

/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#include "GPIO_Private.h"

/* MODE : INPUT   OR   OUTPUT */
#define INPUT  0
#define OUTPUT 1

/* VALUE : HIGH   OR   LOW */
#define HIGH 1
#define LOW  0

/* EROOR STATE */
typedef enum
{
	GPIO_OK,
	GPIO_ERROR
}GPIO_STATE;


/* REG OPTIONS */
#define GPIOA 5
#define GPIOB 6
#define GPIOC 7
#define GPIOD 8

/* PIN OPTIONS */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

GPIO_STATE GPIO_void_Set_Direction_PIN(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8MODE);

GPIO_STATE GPIO_void_Set_Value_PIN(u8 Copy_u8REG , u8 Copy_u8PIN , u8 Copy_u8VALUE);

GPIO_STATE GPIO_void_Set_PULL_UP(u8 Copy_u8REG , u8 Copy_u8PIN);

GPIO_STATE GPIO_void_Toggle_PIN(u8 Copy_u8REG , u8 Copy_u8PIN);

GPIO_STATE GPIO_void_SET_PORT_VALUE(u8 Copy_u8REG , u8 Copy_u8VALUE);
GPIO_STATE GPIO_void_SET_PORT_DIR(u8 Copy_u8REG  ,u8 Copy_u8MODE);
u8 GPIO_void_ReadPIN(u8 Copy_u8REG , u8 Copy_u8PIN );

#endif

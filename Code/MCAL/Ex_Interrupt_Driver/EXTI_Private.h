/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"


#define NULL ((void*) 0)

/* OFFSET ADDRESS FOR SFR */
#define __SFR_OFFSET   0x20

#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
    void vector (void)

#define EXTI0_VECTOR	__vector_1
#define EXTI1_VECTOR	__vector_2
#define EXTI2_VECTOR	__vector_3

#define MCUCR  _MMIO_BYTE(0x35 + __SFR_OFFSET)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR _MMIO_BYTE(0x34 + __SFR_OFFSET)
#define ISC2 6

#define GICR   _MMIO_BYTE(0x3B + __SFR_OFFSET)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR   _MMIO_BYTE(0x3A + __SFR_OFFSET)

#define SREG   _MMIO_BYTE(0x3F + __SFR_OFFSET)
#define GIE_PIN 7



#endif

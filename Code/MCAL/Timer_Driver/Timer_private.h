/*
 * Timer_private.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_PRIVATE_C_
#define MCAL_TIMER_DRIVER_TIMER_PRIVATE_C_
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#define OFFSET_ADDRESS 0x20

#define NULL ((void*) 0)

#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
		void vector (void)

/* Timer/Counter Control Register */
#define TCCR0 _MMIO_BYTE(OFFSET_ADDRESS + 0x33)
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOCO  7
/* Timer Counter Register */
#define TCNT0 _MMIO_BYTE(OFFSET_ADDRESS + 0x32)


/*output compare Register */
#define OCR0 _MMIO_BYTE(OFFSET_ADDRESS + 0x3C)

/* Timer Interrupt MASK */
#define TIMSK _MMIO_BYTE(OFFSET_ADDRESS + 0x39)
#define TOIE0 0
#define OCIE0 1

/* Timer Interrupt Flag Register*/
#define TIFR _MMIO_BYTE(OFFSET_ADDRESS + 0x38 )
#define TOV0 0
#define OCF0 1

#define TIMER0_OUTCOMP_VECTOR   __vector_10
#define TIMER0_OVERFLOW_VECTOR  __vector_11




#define TCCR2 _MMIO_BYTE(OFFSET_ADDRESS + 0x25)
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOCO  7
/* Timer Counter Register */
#define TCNT2 _MMIO_BYTE(OFFSET_ADDRESS + 0x24)


/*output compare Register */
#define OCR2 _MMIO_BYTE(OFFSET_ADDRESS + 0x23)

#define TOIE2 6
#define OCIE2 7


#define TOV0 0
#define OCF0 1

#define TIMER2_OUTCOMP_VECTOR   __vector_4
#define TIMER2_OVERFLOW_VECTOR  __vector_5


#define TCCR1A _MMIO_BYTE(OFFSET_ADDRESS + 0x2F)
#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B _MMIO_BYTE(OFFSET_ADDRESS + 0x2E)
#define CS10  0
#define CS11  1
#define CS12  2

#define WGM12 3
#define WGM13 4

#define ICES1 6
#define ICNC1 7

#define OCR1A _MMIO_BYTE(OFFSET_ADDRESS + 0x2A)
#define OCR1B _MMIO_BYTE(OFFSET_ADDRESS + 0x28)
#define ICR1  _MMIO_BYTE(OFFSET_ADDRESS + 0x26)
#define TCNT1 _MMIO_BYTE(OFFSET_ADDRESS + 0x2C)

#define TOIE1 2
#define OCIE1A 4
#define OCIE1B 3
#define TICIE1 5

#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5


#define TIMER1_OVERFLOW_VECTOR  __vector_9
#define TIMER1_OUTCOMPA_VECTOR  __vector_7
#define TIMER1_OUTCOMPB_VECTOR  __vector_8


#endif /* MCAL_TIMER_DRIVER_TIMER_PRIVATE_C_ */

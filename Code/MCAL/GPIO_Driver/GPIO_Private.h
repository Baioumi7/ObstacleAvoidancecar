/****************************************************** */
/*  Author: BAYOUMII							*/

/****************************************************** */

#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"


/* OFFSET ADDRESS FOR SFR */
#define __SFR_OFFSET   0x20

/* ADDRESSES FOR SFR OF PORTA */
#define DDRA _MMIO_BYTE(0x1A + __SFR_OFFSET)
#define PORTA _MMIO_BYTE(0x1B + __SFR_OFFSET)
#define PINA _MMIO_BYTE(0x19 + __SFR_OFFSET)

/* ADDRESSES FOR SFR OF PORTB */
#define DDRB _MMIO_BYTE(0x17 + __SFR_OFFSET)
#define PORTB _MMIO_BYTE(0x18 + __SFR_OFFSET)
#define PINB _MMIO_BYTE(0x16 + __SFR_OFFSET)

/* ADDRESSES FOR SFR OF PORTC */
#define DDRC _MMIO_BYTE(0x14 + __SFR_OFFSET)
#define PORTC _MMIO_BYTE(0x15 + __SFR_OFFSET)
#define PINC _MMIO_BYTE(0x13 + __SFR_OFFSET)

/* ADDRESSES FOR SFR OF PORTD */
#define DDRD _MMIO_BYTE(0x11 + __SFR_OFFSET)
#define PORTD _MMIO_BYTE(0x12 + __SFR_OFFSET)
#define PIND _MMIO_BYTE(0x10 + __SFR_OFFSET)



#endif

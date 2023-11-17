/*
 * SPI_Private.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_SPI_DRIVER_SPI_PRIVATE_H_
#define MCAL_SPI_DRIVER_SPI_PRIVATE_H_

#include "../../SERVACE_LAYER/DATA_TYPES.h"
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"

#define OFFSET_ADDRESS 0x20



#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
		void vector (void)

#define SPI_TRANSFER_COMPLETE_VECTOR __vector_12


#define SPCR _MMIO_BYTE(OFFSET_ADDRESS + 0x0D)
#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPSR _MMIO_BYTE(OFFSET_ADDRESS + 0x0E)

#define SPIF 7
#define WCOL 6
#define SPI2X 0


#define SPDR _MMIO_BYTE(OFFSET_ADDRESS + 0x0F)

#define MSB 7
#define LSB 0

#define SS PIN4
#define MOSI PIN5
#define MISO PIN6
#define SCK PIN7

#define SPI_PORT GPIOB

#endif /* MCAL_SPI_DRIVER_SPI_PRIVATE_H_ */

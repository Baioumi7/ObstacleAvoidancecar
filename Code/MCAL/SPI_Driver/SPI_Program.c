/*
 * SPI_Program.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Kimo Store
 */
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"

u8 DataRecieved;


ISR(SPI_TRANSFER_COMPLETE_VECTOR)
{

}

void SPI_voidMasterInit()
{
	GPIO_void_Set_Direction_PIN(SPI_PORT , MOSI , OUTPUT);
	GPIO_void_Set_Direction_PIN(SPI_PORT , SCK , OUTPUT);
	GPIO_void_Set_Direction_PIN(SPI_PORT , SS , OUTPUT);

	GPIO_void_Set_Direction_PIN(SPI_PORT , MISO , INPUT);
	GPIO_void_Set_Value_PIN(SPI_PORT , SS , HIGH);

	SET_BIT(SPCR , SPE);
	SET_BIT(SPCR , MSTR);


#if SPI_SPEED == NormalSpeed

#if SPI_CLock_Prescaller == 4
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
#elif SPI_CLock_Prescaller == 16
	SET_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
#elif SPI_CLock_Prescaller == 64
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
#elif SPI_CLock_Prescaller == 128
	SET_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
#endif

#elif SPI_SPEED == DoubleSpeed

#endif

}

void SPI_voidSlaverInit()
{

	GPIO_void_Set_Direction_PIN(SPI_PORT , MOSI , INPUT);
	GPIO_void_Set_Direction_PIN(SPI_PORT , SCK , INPUT);
	GPIO_void_Set_Direction_PIN(SPI_PORT , SS , INPUT);

	GPIO_void_Set_Direction_PIN(SPI_PORT , MISO , OUTPUT);
	SET_BIT(SPCR , SPE);
	CLEAR_BIT(SPCR , MSTR);

}


void SPI_voidMasterSendData(u8 Copy_u8Char)
{
	u8 FlushBuffer;
	SPDR = Copy_u8Char;
	while((CHECK_BIT(SPSR , SPIF)) == 0);
	FlushBuffer = SPDR;
}

void SPI_voidSlaveSendData(u8 Copy_u8Char)
{
	u8 FlushBuffer;
	SPDR = Copy_u8Char;
	while((CHECK_BIT(SPSR , SPIF)) == 0);
	FlushBuffer = SPDR;
}


u8 SPI_voidMasterReceivePolling()
{
	SPDR = 0xFF;  // Dummy Data
	while((CHECK_BIT(SPSR , SPIF)) == 0);
	return SPDR;
}

u8 SPI_voidSlaveReceivePolling()
{
	while((CHECK_BIT(SPSR , SPIF)) == 0);
	return SPDR;
}



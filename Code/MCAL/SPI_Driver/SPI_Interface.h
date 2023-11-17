/*
 * SPI_Interface.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_SPI_DRIVER_SPI_INTERFACE_H_
#define MCAL_SPI_DRIVER_SPI_INTERFACE_H_
#include "SPI_Private.h"

#define NormalSpeed 0
#define DoubleSpeed 1



void SPI_voidMasterInit();
void SPI_voidSlaveInit();

void SPI_voidMasterSendData(u8 Copy_u8Char);
void SPI_voidSlaveSendData(u8 Copy_u8Char);

u8  SPI_voidMasterReceivePolling();
u8 SPI_voidSlaveReceivePolling();

#endif /* MCAL_SPI_DRIVER_SPI_INTERFACE_H_ */

/*
 * SPI_Config.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_SPI_DRIVER_SPI_CONFIG_H_
#define MCAL_SPI_DRIVER_SPI_CONFIG_H_

/* Options
 * 1) NormalSpeed
 * 2) DoubleSpeed */

#define SPI_SPEED NormalSpeed

/* Options
 For Normal Speed
 * 1) 4
 * 2) 16
 * 3) 64
 * 4) 128
 *
 For Double Speed
 * 1) 2
 * 2) 8
 * 3) 32
 * 4) 64
 * */

#define SPI_CLock_Prescaller 16


#endif /* MCAL_SPI_DRIVER_SPI_CONFIG_H_ */

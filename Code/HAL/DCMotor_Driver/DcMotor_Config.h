/*
 * DcMotor_Config.h
 *
 Author: BAYOUMII
 */

#ifndef HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_
#define HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_

/*
 * in SetDuty Function you must put value from 0 to 255
 * because Timer0 Register is 8 bit register
 *
 * 100 % DutyCycle -- > 255
 * 50 %  DutyCycle -- > 127
 * 0 %   DutyCycle -- > 0
 *
 * */
#define MotorsNumber 4

typedef struct
{
	u8 MotorPort;
	u8 MotorPin1;
	u8 MotorPin2;
}MototCfg;

MototCfg M_arr[MotorsNumber] = {
		{GPIOA,PIN0,PIN1},
		{GPIOA,PIN2,PIN3},
		{GPIOA,PIN4,PIN5},
		{GPIOA,PIN6,PIN7},
};



#endif /* HAL_DCMOTOR_DRIVER_DCMOTOR_CONFIG_H_ */

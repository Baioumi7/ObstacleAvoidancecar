/*
 * LCD.h
 *
 Author: BAYOUMII
 */

#ifndef LCD_H_
#define LCD_H_

//#include <stdlib.h>
#include "../../SERVACE_LAYER/MACRO_FUNCTIONS.h"
#include "../../MCAL/GPIO_Driver/GPIO_Interface.h"
#include <util/delay.h>

#define LCD_BIT_MODE 4
#define RS 0
#define E 1

#define LCD_CTRL_PORT_RS PORTC
#define LCD_CTRL_PORT_DIR_RS DDRC
#define LCD_CTRL_PORT_E PORTC
#define LCD_CTRL_PORT_DIR_E DDRC
#define LCD_DATA_PORT PORTB
#define LCD_DATA_PORT_DIR DDRB

#define _8BIT_2LINE (0x38)
#define _4BIT_2LINE (0x28)
#define DISPLAY_ON_CURSOR_ON (0x0E)
#define DISPLAY_ON_CURSOR_OFF (0x0C)
#define CLEAR_DISPLAY (0x01)
#define SET_CURSOR_LOCATION (0x80)
#define ReturnHome (0x02)

void LCD_Init(void);
void LCD_Clear_Display(void);
void LCD_Send_Command(unsigned char command);
void LCD_Send_character(char character);
void LCD_Send_String(char *string);
void LCD_GoTO_Row_Colunmn(char Row,char Column);
void LCD_Send_String_Row_Column(char Row,char Column,char *String);
void LCD_reverse(char* str, int len);
void LCD_intToStr(int x, char *str , int d);
void LCD_FloatToString(double n, char* res);
void LCD_MergTwoStrings(char *str1, char *str2 , char *resStr);
void LCD_Set_Custom_Char(unsigned char Location ,unsigned char * Pattern);



#endif /* LCD_H_ */

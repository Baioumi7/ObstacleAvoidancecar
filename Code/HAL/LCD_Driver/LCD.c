/*
 * LCD.c
 *
 Author: BAYOUMII
 */
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*LCD initialization & clearing*/
void LCD_Init(void)
{
	LCD_CTRL_PORT_DIR_RS |=(1<<RS);
	LCD_CTRL_PORT_DIR_E  |=(1<<E);

#if LCD_BIT_MODE  == 4
	LCD_DATA_PORT_DIR |=0x0F;
	LCD_Send_Command(ReturnHome);
	LCD_Send_Command(_4BIT_2LINE);

#elif LCD_BIT_MODE == 8
	LCD_DATA_PORT_DIR=0xff;
	LCD_Send_Command(ReturnHome);
	LCD_Send_Command(_8BIT_2LINE);
#endif
	_delay_ms(1);
	LCD_Send_Command(CLEAR_DISPLAY);
	LCD_Send_Command(DISPLAY_ON_CURSOR_OFF);
}

/*Sending A command to the LCD */
void LCD_Send_Command(unsigned char command)
{
	/*LCD as 8bit mode*/
#if LCD_BIT_MODE == 8
	LCD_CTRL_PORT_RS &=~(1<<RS); // command mode
	_delay_ms(1);
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);
	LCD_DATA_PORT =command;
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);

	/*LCD as 8bit mode*/
#elif LCD_BIT_MODE == 4
	LCD_CTRL_PORT_RS &=~(1<<RS); // command mode
	_delay_ms(1);
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);
	/* Clearing Data Port  For new Data*/
	LCD_DATA_PORT &= (0xF0);
	LCD_DATA_PORT =((command>>4)&0x0F);
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);

	LCD_CTRL_PORT_RS &=~(1<<RS); // command mode
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);
	/* Clearing Data Port  For new Data*/
	LCD_DATA_PORT &= (0xF0);
	LCD_DATA_PORT |=(command&0x0F);
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);
#endif

}
/*LCD Clearing the display*/
void LCD_Clear_Display(void)
{
	LCD_Send_Command(CLEAR_DISPLAY);
}

/*LCD displaying a character*/
void LCD_Send_character(char character)
{
	/*LCD as 8bit mode*/
#if LCD_BIT_MODE == 8
	LCD_CTRL_PORT_RS |=(1<<RS);// Data mode
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);
	LCD_DATA_PORT =character;
	_delay_ms(1);
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);

	/*LCD as 8bit mode*/
#elif LCD_BIT_MODE == 4
	LCD_CTRL_PORT_RS |=(1<<RS); // Data mode
	_delay_ms(1);
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);

	/* Clearing Data Port  For new Data*/
	LCD_DATA_PORT &= (0xF0);
	LCD_DATA_PORT =((character >> 4) & 0x0F);
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);

	LCD_CTRL_PORT_RS |=(1<<RS); // Data mode
	LCD_CTRL_PORT_E |=(1<<E);
	_delay_ms(1);
	/* Clearing Data Port  For new Data*/
	LCD_DATA_PORT &= (0xF0);
	LCD_DATA_PORT =(character & 0x0F);
	LCD_CTRL_PORT_E &=~(1<<E);
	_delay_ms(1);
#endif
}

/*LCD displaying a String*/
void LCD_Send_String(char *string)
{
	int i=0;
	while(string[i]!='\0')
	{
		LCD_Send_character(string[i]);
		i++;
	}
}

/*set the cursor at certain location*/
void LCD_GoTO_Row_Colunmn(char Row,char Column)
{
	unsigned char address=0;

	switch (Row)
	{
	case 0:address =(Column);break;
	case 1:address =(Column+0x40);break;
	case 2:address =(Column+0x10);break;
	case 3:address =(Column+0x50);break;
	}

	/* we need to apply the corresponding command 0b10000000+Address */
	LCD_Send_Command(address|(SET_CURSOR_LOCATION));

}

/*lcd Send String at certain location*/
void LCD_Send_String_Row_Column(char Row,char Column,char *String)
{
	LCD_GoTO_Row_Colunmn(Row,Column);
	LCD_Send_String(String);
}

/*since the lcd is alpha Numeric print characters only*/

void LCD_reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
void LCD_intToStr(int x, char *str , int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	LCD_reverse(str, i);
	str[i] = '\0';

	//itoa(x,str , 10);
}

void LCD_MergTwoStrings(char *str1, char *str2 , char *resStr)
{
	int i = 0, j = 0;
	while (str1[i] != '\0') {
		resStr[j] = str1[i];
		i++;
		j++;
	}

	// Insert the second string
	// in the new string
	resStr[j++] = '.';
	i = 0;
	while (str2[i] != '\0') {
		resStr[j] = str2[i];
		i++;
		j++;
	}
	resStr[j] = '\0';
}
void LCD_FloatToString(double n, char* res)
{
	/*
	// Extract integer part
	int ipart = (int)n;
	u8 inpartStr[10] , fpartStr[5] ;
	LCD_intToStr(ipart , inpartStr);

	// Extract floating part
	float fpart = n - (float)ipart;
	LCD_intToStr((int)(fpart*100) , fpartStr);

	LCD_MergTwoStrings(inpartStr , fpartStr , res);
	 */

}

/***********************************************************************
 * Function    :LCD_Set_Custom_Char(unsigned char Location , unsigned char * Pattern);
 *
 * DESCRIPTION : This function used to upload a custom char which user wants to map
 * 				it using CGRAM (Character Generator Ram Address set).
 *
 * PARAMETERS  : location : to define which CGRAM ADD offset. It takes from (0 to 7)
 * 						   as CGRAM has 64bytes and LCD as 5x8 dots in function set then you
 * 						   can define a total of 8 user defined patterns (1 Byte for each row
 * 						   and 8 rows for each pattern).
 * 				Pattern: pointer to 8 pointer to char as CGRAM needs 8 char to map
 *
 * Return Value: Void.
 ***********************************************************************/

void LCD_Set_Custom_Char(unsigned char Location , unsigned char * Pattern)
{
	unsigned char ArrayIndex =0;
	/* the Add offset must be 0 to 7*/
	if (Location < 8)
	{
		LCD_Send_Command(0x40 + (Location * 8));
		for (ArrayIndex = 0; ArrayIndex < 8; ArrayIndex++)
		{
			LCD_Send_character(Pattern[ArrayIndex]);
		}
	}
	else
	{
		/* TODO: return Error */
	}
}

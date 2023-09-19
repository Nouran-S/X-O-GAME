#include <util/delay.h>
#include "STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"

// Initialize LCD:
void LCD_VidINIT()
{
	DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, Output);
	DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, Output);
	DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, Output);

	DIO_VidSetPortDirection(LCD_DATA_PORT, 0xff);
    _delay_ms(40);

    // Function set command: 2 lines, 5*8 Font size
    LCD_VidSendCmd(0x38);

    // Dispaly on off control: display enable, disable cursor, on blink cursor
    LCD_VidSendCmd(0x0c);

    // Clear display:
    LCD_VidSendCmd(0x01);
}

// Send Data To LCD:
void LCD_VidSendData(u8 data)
{
    // RW = 0 [Write]
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, Low);

    // RS = 1 [Data]
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, High);

    // Write data on Data PORT [PORT A]
    DIO_VidSetPortValue(LCD_DATA_PORT, data);

    // Pulse:
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, High);
    _delay_ms(2);
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, Low);
}

// Send Command To LCD:
void LCD_VidSendCmd(u8 cmd)
{
    // RW = 0 [Write]
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, Low);

    // RS = 0 [CMD]
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, Low);

    // Write CMD on Data PORT [PORT A]
    DIO_VidSetPortValue(LCD_DATA_PORT, cmd);

    // Pulse:
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, High);
    _delay_ms(2);
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, Low);
}

// Send string To LCD:
void LCD_VidSendStr(u8 *str)
{
	for(int i=0; str[i] != 0; i++)
	{
		if (i == 16)
			LCD_VidMoveCursor(1, 0);

		LCD_VidSendData(str[i]);
	}
}

// Send number To LCD:
void LCD_VidSendInt(u8 number)
{
	char buffer[10];
	itoa(number,buffer,10);
	LCD_VidSendStr(buffer);
}

// Clear The Screen:
void LCD_VidClear()
{
	LCD_VidSendCmd(0x01);
}

// Move the cursor:
void LCD_VidMoveCursor(u8 x, u8 y)
{
	// First Line:
	if(x == 0)
		LCD_VidSendCmd(0x80);

	// second Line:
	else if(x == 1)
		LCD_VidSendCmd(0xC0);


	if(y>=0 && y<=15)
		for(int i=0; i<y; i++)
			LCD_VidSendCmd(0x14);
}





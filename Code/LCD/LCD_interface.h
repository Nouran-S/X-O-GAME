#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "STD_TYPES.h"

// Initialize LCD:
void LCD_VidINIT();

// Send Data To LCD:
void LCD_VidSendData(u8 data);

// Send Command To LCD:
void LCD_VidSendCmd(u8 cmd);

// Write String on LCD:
void LCD_VidSendStr(u8 *str);

// Write Int on LCD:
void LCD_VidSendInt(u8 number);

// Clear Screen:
void LCD_VidClear();

// Move the cursor:
void LCD_VidMoveCursor(u8 x, u8 y);
#endif

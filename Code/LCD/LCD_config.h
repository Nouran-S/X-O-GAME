#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "../DIO/DIO_interface.h"

#define LCD_DATA_PORT   Port_A
#define LCD_CTRL_PORT   Port_B

#define LCD_RS_PIN      pin_0 // RS:0[data] || RS:1[cmd]
#define LCD_RW_PIN      pin_1 // RW:0[write] || RW:1[read]
#define LCD_EN_PIN      pin_2 // EN:0[disable] || EN:1[enable]

#endif

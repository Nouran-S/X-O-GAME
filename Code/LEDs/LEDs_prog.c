#include "LEDs_Interface.h"
#include "../DIO/DIO_interface.h"
#include <avr/io.h>


void LEDs_VidINIT()
{
    // Output:
    DIO_VidSetPinDirection(Port_B, pin_7, 0x01);
    DIO_VidSetPortDirection(Port_D, 0xff);
    DDRD = 0xff;
}

void LEds_Vid_All_X_On()
{
	LEDs_VidINIT();
    // All X LEDs On:
    DIO_VidSetPinValue(Port_B, pin_7, Low);
    DIO_VidSetPortValue(Port_D, 0x00);
}

void LEds_Vid_All_O_On()
{
    // All O LEDs On:
    DIO_VidSetPinValue(Port_B, pin_7, High);
    DIO_VidSetPortValue(Port_D, 0xff);
}

void LEDs_Vid_Select(u8 player, u8 n)
{
    u8 on;

    // Select the player:
    if (player == 'X' || player == 'x')
    	on = 0;

    else
        on = 1;


    // Led on:
    if (n == 9)
    {
    	DIO_VidSetPinDirection(Port_B, pin_7, Output);
		DIO_VidSetPinValue(Port_B, pin_7, on);
    }

    else if (n > 0 && n < 9)
    {
    	DIO_VidSetPinDirection(Port_D, n-1, Output);
		DIO_VidSetPinValue(Port_D, n-1, on);
    }
}

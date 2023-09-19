#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "DIO_interface.h"

void DIO_VidSetPinDirection(u8 port, u8 pin, u8 dic){
    if (dic == Input)
    {
        switch (port)
        {
        case Port_A: 
            Clear_bit(DDRA, pin);
            break;

        case Port_B:
            Clear_bit(DDRB, pin);
            break;

        case Port_C:
            Clear_bit(DDRC, pin);
            break;

        case Port_D:
            Clear_bit(DDRD, pin);
            break;
        } // end switch
    } // end if

    else if (dic == Output)
    {
        switch (port)
        {
        case Port_A:
            Set_bit(DDRA, pin);
            break;

        case Port_B:
            Set_bit(DDRB, pin);
            break;

        case Port_C:
            Set_bit(DDRC, pin);
            break;

        case Port_D:
            Set_bit(DDRD, pin);
            break;
        } // end switch
    } // end else if

}

void DIO_VidSetPinValue(u8 port, u8 pin, u8 val)
{
    if (val == Low)
    {
        switch (port)
        {
        case Port_A:
            Clear_bit(PORTA, pin);
            break;

        case Port_B:
            Clear_bit(PORTB, pin);
            break;

        case Port_C:
            Clear_bit(PORTC, pin);
            break;

        case Port_D:
            Clear_bit(PORTD, pin);
            break;
        } // end switch
    }     // end if

    else if (val == High)
    {
        switch (port)
        {
        case Port_A:
            Set_bit(PORTA, pin);
            break;

        case Port_B:
            Set_bit(PORTB, pin);
            break;

        case Port_C:
            Set_bit(PORTC, pin);
            break;

        case Port_D:
            Set_bit(PORTD, pin);
            break;
        } // end switch
    }     // end else if
}

void DIO_VidGetPinValue(u8 port, u8 pin, u8 *data)
{
    switch (port)
    {
    case Port_A:
        *data = Get_bit(PINA, pin);
        break;
    case Port_B:
        *data = Get_bit(PINB, pin);
        break;
    case Port_C:
        *data = Get_bit(PINC, pin);
        break;
    case Port_D:
        *data = Get_bit(PIND, pin);
        break;
    }
}

void DIO_VidSetPortDirection(u8 port, u8 dic)
{
    if (dic == Input)
    {
        switch (port)
        {
        case Port_A:
            DDRA = 0x00;
            break;
        case Port_B:
            DDRB = 0x00;
            break;
        case Port_C:
            DDRC = 0x00;
            break;
        case Port_D:
            DDRD = 0x00;
            break;
        }
    }

    else if (dic == Output)
    {
        switch (port)
        {
        case Port_A:
            DDRA = 0xff;
            break;
        case Port_B:
            DDRB = 0xff;
            break;
        case Port_C:
            DDRC = 0xff;
            break;
        case Port_D:
            DDRD = 0xff;
            break;
        }
    }

}

void DIO_VidSetPortValue(u8 port, u8 value)
{
    switch (port)
    {
    case Port_A:
        PORTA = value;
        break;
    case Port_B:
        PORTB = value;
        break;
    case Port_C:
        PORTC = value;
        break;
    case Port_D:
        PORTD = value;
        break;
    }
}

void DIO_VidGetPortValue(u8 port, u8 *value)
{
    switch (port)
    {
    case Port_A:
        *value = PINA;
        break;
    case Port_B:
        *value = PINB;
        break;
    case Port_C:
        *value = PINC;
        break;
    case Port_D:
        *value = PIND;
        break;
    }
}


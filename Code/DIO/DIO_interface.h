#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"

typedef enum
{
    Port_A,
    Port_B,
    Port_C,
    Port_D
} et_port;

typedef enum
{
    pin_0,
    pin_1,
    pin_2,
    pin_3,
    pin_4,
    pin_5,
    pin_6,
    pin_7,
} et_pin;

typedef enum
{
    Input,
    Output
} et_Direction;

typedef enum
{
    Low,
    High
} et_Status;

// Set Pin Direction: Input || Output
void DIO_VidSetPinDirection(u8 port, u8 pin, u8 dic);

// Set Pin Value: Low || High
void DIO_VidSetPinValue(u8 port, u8 pin, u8 val);

// Get Pin Value
void DIO_VidGetPinValue(u8 port, u8 pin, u8 *data);

// Set Port Direction: Input || Output
void DIO_VidSetPortDirection(u8 port, u8 dic);

// Set Port Value: Low || High
void DIO_VidSetPortValue(u8 port, u8 value);

// Get Port Value: Low || High
void DIO_VidGetPortValue(u8 port, u8 *value);

#endif

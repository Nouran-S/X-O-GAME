#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include "STD_TYPES.h"

u8 whoTakeThisPlace[9];   // 0: O ||  1: X || -1: No one
u8 emptyOrfull[9]; // 0: empty || 1: full
//u8 winner = 2; // 2: No one || 1: X || 0: O

void Vid_InitGame();
void Vid_SetFull(u8 index);
u8 U8_IsFull(u8 index);
void Vid_SetPlayer(u8 player, u8 place);

#endif

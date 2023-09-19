#include "Game_interface.h"
#include "STD_TYPES.h"

void Vid_InitGame()
{
    for (int i = 0; i < 9; i++)
    {
        emptyOrfull[i] = 0;
        whoTakeThisPlace[i] = 2;
    }
}

void Vid_SetFull(u8 index){
    emptyOrfull[index] = 1;
}

u8 U8_IsFull(u8 index)
{
    return emptyOrfull[index];
}

void Vid_SetPlayer(u8 player, u8 place)
{
	if (player == 'x' || player == 'X')
		whoTakeThisPlace[place] = 1;

	else if (player == 'o' || player == 'O')
		whoTakeThisPlace[place] = 0;
}

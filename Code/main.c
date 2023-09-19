/*
 * main.c
 *
 *  Created on: 15 Sept 2023
 *      Author: Nouran S.
 */

#include <avr/io.h>
#include <util/delay.h>
#include "DIO/DIO_interface.h"
#include "LEDs/LEDs_Interface.h"
#include "KPD/KPD_interface.h"
#include "LCD/LCD_interface.h"
#include "Game_interface.h"

void Vid_ShowWinner(u8 n);
void Vid_Play(u8 player);
void Vid_SelectPlayer(u8 counter);
u8 U8_WhoWin(); // 0[O win], 1[X win], -1[No winers]

int main()
{
	u8 counter = 1;

	LCD_VidINIT();
	Vid_InitGame();

	u8 w = U8_WhoWin();
	u8 end;

	while (1)
	{
		LCD_VidClear();
		w = U8_WhoWin();

		if(w == 0) // O Win
			Vid_ShowWinner(0);

		else if(w == 1) // X Win
			Vid_ShowWinner(1);

		else if(w == 2 && counter >=10) // No Winners
			Vid_ShowWinner(2);

		else if(w == 2 && counter <10) // Playing
		{
				Vid_SelectPlayer(counter);
				counter++;
		}

	}
}

void Vid_ShowWinner(u8 n)
{
	LCD_VidClear();
	LCD_VidSendStr("Game Over ..");
	LCD_VidMoveCursor(1, 0);

	if(n == 0)
		LCD_VidSendStr("O Win ..!");

	else if(n == 1)
			LCD_VidSendStr("X Win ..!");

	else if(n == 2)
			LCD_VidSendStr("No Winners ..!");

	_delay_ms(500);
	LEds_Vid_All_X_On();
	_delay_ms(500);
	LEds_Vid_All_O_On();
}

void Vid_Play(u8 player)
{
	u8 ch;
	u8 n, index;
	u8 arr[7] = {'*', '/', '+', '-', '0', '=', ' '};

	LCD_VidClear();
	LCD_VidSendData(player);
	LCD_VidSendStr(" is Playing");
	LCD_VidMoveCursor(1, 0);
	LCD_VidSendStr("Choose Number: ");

	_delay_ms(1000);
	ch = KPD_U8Pressed();
	n = ch - '0';
	index = n - 1;

	LCD_VidSendInt(n);

	for (int i=0; i<7; i++)
		if(ch == arr[i])
		{
			LCD_VidClear();
			LCD_VidSendStr("Wrong Place");
			LCD_VidMoveCursor(1, 0);
			LCD_VidSendStr("Try Again ..!");
			_delay_ms(1000);
			Vid_Play(player);
		}

	_delay_ms(50);


	if (U8_IsFull(index) == 0)
	{
		// Put 1 in emptyOrfull array: Full
		Vid_SetFull(index); 
		// put [0 or 1] in whoTakeThisPlace array:
		Vid_SetPlayer(player, index); 
	}

	else
	{
		LCD_VidClear();
		LCD_VidSendStr("Wrong Place");
		LCD_VidMoveCursor(1, 0);
		LCD_VidSendStr("Try Again ..!");
		_delay_ms(1000);
		Vid_Play(player);
	}

	LEDs_Vid_Select(player, n);
	_delay_ms(200);
}

void Vid_SelectPlayer(u8 counter)
{
	u8 player;

	if(counter%2 == 0)
		player = 'O';
	else
		player = 'X';

	Vid_Play(player);
}

u8 U8_WhoWin()
{
	u8 group[8][3] = {
			{0, 1, 2}, 
			{3, 4, 5},
			{6, 7, 8},
			{0, 3, 6},
			{1, 4, 7},
			{2, 5, 8},
			{0, 4, 8},
			{2, 4, 6} };

	u8 *player; 
	u8 winner = 2;

	for(int i=0; i<8; i++)
	{
		player = group[i];
		if(whoTakeThisPlace[player[0]] == whoTakeThisPlace[player[1]] &&
				whoTakeThisPlace[player[0]] == whoTakeThisPlace[player[2]] &&
				whoTakeThisPlace[player[0]] != 2)
		{
			winner = whoTakeThisPlace[player[0]];
			break;
		}
	}

	return winner;
}

#pragma once
#include "menu.h"
using namespace std;
void MENU1(char &chose)
{
	gotoXY(60, 15);
	setBackgroundColor(14);
	SetColor(4);
	cout << "        PRESS ENTER TO PLAY GAME        ";
	gotoXY(60, 16);
	cout << "         PRESS T TO LOAD GAME           ";
	gotoXY(60, 17);
	cout << "         PRESS A TO ABOUT GAME          ";
	gotoXY(60, 18);
	cout << "         PRESS ESC TO EXIT GAME         ";
	
	while (true)
	{
		chose = _getch();
		if (chose == 13 || chose == 27 || chose == 't' || chose == 'a')
			break;
	}
	setBackgroundColor(0);
}
void MENU2(char &chose)
{
	
	gotoXY(69, 27);
	SetColor(13);
	cout << " PRESS ENTER TO MENU";
	gotoXY(69, 28);
	cout << "PRESS ESC TO EXIT GAME";
	while (true)
	{
		chose = _getch();
		if (chose == 13 || chose == 27)
			break;
	}
	if (chose == 13)
	{
		system("cls");
		MENU1(chose);
	}
}
void MENU3()
{
	SetColor(8);
	gotoXY(120, 23);
	cout << "______________________________";
	gotoXY(120, 28);
	cout << "______________________________";
	for (int y = 24; y <= 28; y++)
	{
		gotoXY(119, y);
		cout << "|";
		gotoXY(150, y);
		cout << "|";
	}
	SetColor(10);
	gotoXY(125, 25);
	cout << "PRESS L TO SAVE GAME";
	gotoXY(125, 26);
	cout << "PRESS P TO PAUSE GAME";
	gotoXY(125, 27);
	cout << "PRESS ESC TO EXIT GAME";
}
void MENU4(char &chose,int x)
{
	setBackgroundColor(14);
	SetColor(4);
	gotoXY(x, 15);
	cout << "     ARE YOU WANT TO EXIT GAME?    ";
	gotoXY(x, 16);
	cout << "          NO : PRESS ENTER         ";
	gotoXY(x, 17);
	cout << "          YES : PRESS ESC          ";
	setBackgroundColor(0);
	while (true)
	{
		chose = _getch();
		if (chose == 13 || chose == 27 )
			break;
	}
}
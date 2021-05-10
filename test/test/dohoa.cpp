#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include "dohoa.h"
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
HANDLE hConsoleOutput;
HANDLE hConsoleInput;
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Ham xoa man hinh khong bi dut(lag).
void clrscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	COORD Home = { 0, 0 };
	DWORD dummy;

	hConsoleOutput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	FillConsoleOutputCharacter(hConsoleOutput, ' ', screen_buffer_info.dwSize.X * screen_buffer_info.dwSize.Y, Home, &dummy);
	screen_buffer_info.dwCursorPosition.X = 0;
	screen_buffer_info.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOutput, screen_buffer_info.dwCursorPosition);
}

// Ham dich chuyen con tro den toa do x, y.
void gotoXY(SHORT x, SHORT y)
{
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Tra ve vi tri x hien tai.
SHORT wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.X;
}

// Tra ve vi tri y hien tai.
SHORT wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.Y;
}

// Ham to mau.
void SetColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Ham thay doi mau nen hien thi.
void setBackgroundColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4; // Dich trai 3 bit de phu hop voi mau nen
	wAttributes &= 0xff0f; // Cai 0 cho 1 bit chu nhay va 3 bit mau nen
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

WORD textattr()
{
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	return ConsoleInfo.wAttributes;
}

void resettextattr()
{
	DWORD Mau_Mac_Dinh = textattr();
	SetConsoleTextAttribute(hConsoleOutput, Mau_Mac_Dinh);
}

// Ham in mau chu va thay doi mai nen hien thi theo vi tri x, y.
void setColorBGTextXY(SHORT x, SHORT y, WORD color, WORD background, LPSTR str, ...)
{
	gotoXY(x, y);
	setBackgroundColor(background);
	SetColor(color);

	/*In duoc nhieu chu hon*/
	va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);
	/*In duoc nhieu chu hon*/

	resettextattr();
	//setColor(7);
}

// Ham an hien con tro.
void Cursor(BOOL bVisible, DWORD dwSize)
{
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.bVisible = bVisible;
	ConsoleCursorInfo.dwSize = dwSize; // Phan tram bao trum o cua con tro chuot
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

// Xoa so luong dong, SStartPos - Vi tri bat dau xoa, SNumberRow so luong dong can xoa.
void deleteRow(SHORT SStartPos, SHORT SNumberRow)
{
	CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
	COORD Pos = { 0, SStartPos };
	DWORD Tmp;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	FillConsoleOutputCharacter(hConsoleOutput, ' ', ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	FillConsoleOutputAttribute(hConsoleOutput, 15, ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	SetConsoleCursorPosition(hConsoleOutput, Pos);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
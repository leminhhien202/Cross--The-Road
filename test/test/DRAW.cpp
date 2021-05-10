#pragma once
#include "DRAW.h"
using namespace std;
/*string sticker[4] = {
      "  ** ",
      "******",
      "  **",
      "**  **",
};*/
//hàm vẽ bảng điểm
string sticker[4] = {
    "      __",
    "    /  ~'-*",
    " *--|_| --'",
    "(_)...(_)",
};
string stickerleft[4] = {
    "   __",
    "*-'~  \\",
    "'-- |_|--*",
    "  (_)...(_)",
};
void Draw_Board_Score()
{
    SetColor(4);
    gotoXY(132, 6);
    cout << "SCORE";
    SetColor(8);
    gotoXY(120, 7);
    cout << "______________________________";
    gotoXY(120, 16);
    cout << "______________________________";
    for (int y = 8; y <= 16; y++)
    {
        gotoXY(119, y);
        cout << "|";
        gotoXY(150, y);
        cout << "|";
    }


}
// vẽ khung 
void DrawBoard(int x, int y, int width, int height)
{

    SetColor(8);
    gotoXY(x, y); cout << "_";
    for (int i = 1; i < width; i++)cout << "_";
    {
        Sleep(5);
        cout << "_";
    }
    gotoXY(x, height + y); cout << "|";
    for (int i = 1; i < width; i++)cout << "_";
    {Sleep(5);
    cout << "|";
    }
    for (int i = y + 1; i < height + y; i++)
    {
        Sleep(5);
        gotoXY(x, i); cout << "|";
        gotoXY(x + width, i); cout << "|";
    }
    int bienx = 8;
    while (bienx < 30)
    {

        gotoXY(6, bienx);
        Sleep(100);
        cout << "____________________________________________________________________________________________________";
        bienx += 5;
    }
    gotoXY(0, 0);
}
// vẽ người
void DrawSticker(int& x, int y)
{

    SetColor(10);
    for (int i = 0; i < 4; i++)
    {
        gotoXY(x, y);
        for (int j = 0; j < sticker[i].size(); j++)
            cout << sticker[i][j];
        cout << endl;
        y++;
    }

}
void DrawStickerLeft(int& x, int y)
{

    SetColor(10);
    for (int i = 0; i < 4; i++)
    {
        gotoXY(x, y);
        for (int j = 0; j < stickerleft[i].size(); j++)
            cout << stickerleft[i][j];
        cout << endl;
        y++;
    }

}
//xóa người
void EraseSticker(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        gotoXY(x, y);
        for (int j = 0; j < 11; j++)
            cout << " ";
        cout << endl;
        y++;
    }
}
#pragma once
#include "level.h"

using namespace std;
int random(int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}

int x_random(int x)
{
    if (x < 87)
        return random(x, x + 10);
    if (x > 26)
        return random(x, x - 10);
}
int LEVEL(int tmp)
{
    srand((int)time(0));
    if (tmp == 0)
        return 10;
    if(tmp==1)
       return random(1, 10);
    if (tmp == 2)
        return random(1, 5);
    if (tmp == 3)
    {
        return 10;
    }
    if (tmp == 4)
        return random(1,10);
    return random(1, 5);
}

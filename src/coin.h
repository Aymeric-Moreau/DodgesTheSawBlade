#pragma once
#include "raylib.h"
#include "utils.h"
#ifndef COIN


class coin
{
private:

    Rectangle rec{0,0,15,15};
    Color color = YELLOW;
    int reward = 1;
public:
    coin(Vector2 startPos);
    ~coin();
    void setPosition(Vector2 newPos);
    void drawCoin();
    int getRewardValue();
    Rectangle getRec();
};

#endif
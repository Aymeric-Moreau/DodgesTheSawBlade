#pragma once
#include "raylib.h"

#include "utils.h"
#include "bouton.h"
#include "state.h"
#include "gameManager.h"
#include "inMainGameState.h"

#ifndef MAINMENUSTATE
class mainMenuState : public state
{
private:
    Rectangle recPlayBtn = {0, 0, 100, 100};


bouton playBtn = bouton(recPlayBtn, "Start", startGame);
public:
    mainMenuState(/* args */);
    ~mainMenuState();
    void initState();
    void updateLogic();
    void updateDraw();
    static void startGame();
};


#endif
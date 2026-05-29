#pragma once
#include "raylib.h"
#include "../utils.h"
#include "../bouton.h"
#include "state.h"
#include "../gameManager.h"
#include "inMainGameState.h"
#include "../rini.h"

#ifndef GAMEOVERSTATE

class gameOverState : public state
{
private:
    Rectangle recReStartBtn = {0, 0, 100, 100};
    bouton reStartBtn = bouton(recReStartBtn, "Restart", restartGame,BLUE);

    Rectangle recMainMenueBtn = {0, 150, 100, 100};
    bouton mainMenueBtn = bouton(recMainMenueBtn, "Main Menue", goMainMenu,PURPLE);
public:
    gameOverState(/* args */);
    ~gameOverState();
    void initState();
    void updateLogic();
    void updateDraw();
    static void restartGame();
    static void goMainMenu();
};

#endif
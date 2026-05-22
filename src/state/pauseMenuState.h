#pragma once
#include "raylib.h"

#include "../utils.h"
#include "../bouton.h"
#include "state.h"
#include "../gameManager.h"
#include "inMainGameState.h"

#ifndef PAUSEMENUESTATE
class pauseMenuState : public state
{
private:
    Rectangle recResumeBtn = {0, 10, 200, 100};
bouton resumeBtn = bouton(recResumeBtn, "Resume", resumeGame,GRAY);
        Rectangle recMainMenueBtn = {0, 130, 200, 100};
    bouton mainMenueBtn = bouton(recMainMenueBtn, "Main Menue", goMainMenue,RED);
public:
    pauseMenuState(/* args */);
    ~pauseMenuState();
    void initState();
    void updateLogic();
    void updateDraw();
    static void resumeGame();
    static void goMainMenue();
};


#endif
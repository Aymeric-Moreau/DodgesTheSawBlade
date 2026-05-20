#include "mainMenuState.h"

mainMenuState::mainMenuState(/* args */)
{
}

mainMenuState::~mainMenuState()
{
}

    void mainMenuState::initState(){
        AddActiveBouton(playBtn);
            gM.camera.target = {10, 12};
    gM.camera.offset = { gM.SCREENWIDTH / 2.0f, gM.SCREENHEIGHT / 2.0f};
    gM.camera.rotation = 0.0f;
    gM.camera.zoom = 1.0f;
    }
    void mainMenuState::updateLogic(){

        
    }
    void mainMenuState::updateDraw(){

        DrawRectangleRec(recPlayBtn,LIGHTGRAY);
    }

     void mainMenuState::startGame(){
            std::cout << "click start game\n";
        gM.replaceState(std::make_unique<inMainGameState>());
     }
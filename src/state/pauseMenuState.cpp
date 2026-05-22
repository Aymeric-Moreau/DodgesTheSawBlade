#include "pauseMenuState.h"

pauseMenuState::pauseMenuState(/* args */)
{
    isDisagreeOtherLogic = true;
}

pauseMenuState::~pauseMenuState()
{
}

    void pauseMenuState::initState(){
        std::cout << " init resume menue state\n";
        AddActiveBouton(resumeBtn);
        AddActiveBouton(mainMenueBtn);
            gM.camera.target = {10, 12};
    gM.camera.offset = { gM.SCREENWIDTH / 2.0f, gM.SCREENHEIGHT / 2.0f};
    gM.camera.rotation = 0.0f;
    gM.camera.zoom = 1.0f;
    }
    void pauseMenuState::updateLogic(){

        
    }
    void pauseMenuState::updateDraw(){
        std::cout << " update resume menue state\n";
        Color c{80, 80, 80, 100};
        DrawRectangle(-1000,-500,10000,10000,c);
        resumeBtn.drawButton();
        mainMenueBtn.drawButton();
        // DrawRectangleRec(recPlayBtn,LIGHTGRAY);
    }

     void pauseMenuState::resumeGame(){
            std::cout << "click resume  game\n";
        // gM.addState(std::make_unique<inMainGameState>());
        // gM.suppState(this);
        gM.suppState<pauseMenuState>();
     }

     void pauseMenuState::goMainMenue(){
                    gM.haveToChangeState = true;
            gM.StateSuivant = std::make_unique<mainMenuState>();
     }
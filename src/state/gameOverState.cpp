
#include "gameOverState.h"

gameOverState::gameOverState(/* args */)
{
}

gameOverState::~gameOverState()
{
}
    void gameOverState::initState(){
        std::cout << " init game over state\n";
        AddActiveBouton(reStartBtn);
        AddActiveBouton(mainMenueBtn);
            gM.camera.target = {10, 12};
    gM.camera.offset = { gM.SCREENWIDTH / 2.0f, gM.SCREENHEIGHT / 2.0f};
    gM.camera.rotation = 0.0f;
    gM.camera.zoom = 1.0f;
    gM.config = rini_load("data.ini");
    }
    void gameOverState::updateLogic(){

        
    }
    void gameOverState::updateDraw(){

            



    


        std::string l1 = "HighScore";
        DrawText( l1.c_str(),0,-340,32,BLACK);
        DrawText( std::to_string(rini_get_value(gM.config, "highscore")).c_str(),0,-300,30,BLACK);
        std::string l2 = "Score";
        DrawText( l2.c_str(),0,-260,32,BLACK);
        DrawText( std::to_string(gM.coins).c_str(),0,-220,30,BLACK);
                std::string l3 = "Timer";
        DrawText( l3.c_str(),0,-170,32,BLACK);
        DrawText( std::to_string(gM.playerTimer).c_str(),0,-120,30,BLACK);

        reStartBtn.drawButton();
        mainMenueBtn.drawButton();
        
        // DrawRectangleRec(recPlayBtn,LIGHTGRAY);
    }

     void gameOverState::restartGame(){
            std::cout << "click restart game\n";
        gM.replaceState(std::make_unique<inMainGameState>());
        rini_unload(&gM.config);
     }

          void gameOverState::goMainMenu(){
            std::cout << "click main menue\n";
        gM.replaceState(std::make_unique<mainMenuState>());
        rini_unload(&gM.config);
     }
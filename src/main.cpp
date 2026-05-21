#include "raylib.h"
#include "player.h"
#include "utils.h"
#include "ennemis.h"
#include "spawner.h"
#include "obstacle.h"
#include "bouton.h"
#include "state.h"
#include "mainMenuState.h"
#include "inMainGameState.h"



// void addState(std::unique_ptr<state> newState);

Color BACKGROUND = DARKBLUE;
constexpr int SCREENWIDTH = 1540;
constexpr int SCREENHEIGHT = 990;
constexpr Vector2 SPAWNPOINT = {10, 12};
player playerCharacter(SPAWNPOINT); // zone de spawn ennemis {250 , -550} {-260 , -550}

float speed = 500.5;
Vector2 jumpSpeed = {0, -800};
Vector2 gravity = {0, 25};

bool r;
Camera2D camera;

obstacle ground2 = obstacle({-2500, 200}, 5000, 100);
obstacle wallRight2 = obstacle({350, -2500}, 100, 5000);
obstacle wallLefts2 = obstacle({-360, -2500}, 100, 5000);

Rectangle ground = {-2500, 200, 5000, 10};
Rectangle wallRight = {350, -2500, 100, 5000};
Rectangle wallLefts = {-360, -2500, 100, 5000};
Rectangle area = {-350, -800, 800, 1000};


std::array<Rectangle *, 3> limiteMap{&ground, &wallRight, &wallLefts};
std::array<obstacle *, 3> limiteMap2{&ground2, &wallRight2, &wallLefts2};

Vector2 centerPointRec;

std::vector<ennemis> listeEnnemis;
std::vector<ennemis> closeEnnemis;
ennemis test;
spawner spawnerPrincipal;

int limiteMapGauche{area.x};
int limiteMapDroite{area.x + area.width};

float deltaTime;

Vector2 mousePos;

// std::unique_ptr<> c'est une classe de pointeur intélligent 
inMainGameState mainGState = inMainGameState();
std::vector<std::unique_ptr<state>> activeStates;

std::vector<std::unique_ptr<state>> activeLogicStates{gameState::InMainGame};
std::vector<std::unique_ptr<state>> activeDrawStates{gameState::InMainGame}; // std::vector<std::unique_ptr<State>> states;
// std::vector<bouton> activeBouton{testbtn};
// bool stateEstinitialiser;
bool haveclick = false;

Vector2 GetCenterPoint(const Rectangle &r);

int main()
{

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Dodge the SAWBLADE");
    SetTargetFPS(60);
    // gM.activeBouton.push_back(testbtn);
    std::string fullTextCo2 = "Position : X  : ";
    // testbtn = bouton(btn,fullTextCo2, testBouton() );

    gM.addState(std::make_unique<mainMenuState>());
    // startMainGame();

    while (!WindowShouldClose())
    {
        if (gM.haveToChangeState)
        {
            gM.replaceState(std::move(gM.StateSuivant));
            gM.haveToChangeState = false;
        }
        

        gM.deltaTime = GetFrameTime();

if (gM.stateActive)
        {

            for (size_t i = 0; i < gM.activeStates.size(); i++)
        {
            if (i == 0 || !gM.activeStates[i -1]->GetIsDisagreeOtherLogic())
            {

                gM.activeStates[i]->updateLogic();

          if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !haveclick)
        {
            haveclick = true;
            mousePos = GetScreenToWorld2D(GetMousePosition(), gM.camera);
            for (size_t y = 0; y < gM.activeStates[i]->GetActiveBouton().size(); y++)
            {
                if (CheckCollisionPointRec(mousePos, gM.activeStates[i]->GetActiveBouton()[y].getRectangle()))
                {
                    gM.activeStates[i]->GetActiveBouton()[y].onClick();
                    std::cout << "click bouton" << std::endl;
                }
            }
        }
        if (IsMouseButtonUp(MOUSE_BUTTON_LEFT) && haveclick){
            haveclick = false;
        }
                gM.activeStates[i]->GetActiveBouton();
            }
        }

        }






        BeginDrawing();
        ClearBackground(gM.BACKGROUND);
        BeginMode2D(gM.camera);
        if (gM.stateActive)
        {
                    for (size_t i = 0; i < gM.activeStates.size(); i++)
        {
            if (i == 0 ||!gM.activeStates[i -1]->GetIsDisagreeOtherDraw())
            {

                gM.activeStates[i]->updateDraw();
            }
            
            
        }
        }
        




        // DrawRectangleRec(btn, DARKGREEN);

        EndMode2D();

        // drawUI();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// void addState(std::unique_ptr<state> newState){
//     // activeStates.push_back(std::make_unique<inMainGameState>());
//     activeStates.insert(activeStates.begin(), std::move(newState));
//     activeStates[0]->initState();
// }



//

#include "raylib.h"
#include <string>
#include <future>

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include "player.h"
#include "utils.h"
#include "ennemis.h"




constexpr Color BACKGROUND = DARKBLUE;
constexpr int SCREENWIDTH = 1540;
constexpr int SCREENHEIGHT = 990;
constexpr Vector2 SPAWNPOINT = {10 , 12};
player playerCharacter(SPAWNPOINT);



float speed = 500.5;
Vector2 jumpSpeed = {0,-800}; 
Vector2 gravity = {0,25};

bool r;
Camera2D camera;
Rectangle ground = { -2500, 200, 5000, 10 }; //         DrawRectangle(-250, -1000, 500 , 1000 , WHITE);
Rectangle area = { -250, -800, 500 , 1000  }; // playerCharacter.ApplyVelocity(area.x + playerCharacter.TAILLECHARACTER / 2 , area.x + area.width - playerCharacter.TAILLECHARACTER / 2);

ennemis test;

int limiteMapGauche{area.x};
int limiteMapDroite{area.x + area.width};

float deltaTime;



void applyGravity();
void drawUI();


int main()
{

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Raylib jeu de la vie");
    SetTargetFPS(60);
    playerCharacter = player(SPAWNPOINT); // playerCharacter.ApplyVelocity(area.x + playerCharacter.TAILLECHARACTER / 2 , area.x + area.width - playerCharacter.TAILLECHARACTER / 2);
    playerCharacter.SetLimiteMap(limiteMapGauche,limiteMapDroite);
    // Initialisation caméra
    camera.target = { playerCharacter.GetPosition().x, playerCharacter.GetPosition().y };
    camera.offset = { SCREENWIDTH / 2.0f, SCREENHEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        
        deltaTime = GetFrameTime();



        applyGravity();
    

        if (IsKeyDown(KEY_RIGHT))
{
    Vector2 v = playerCharacter.GetVelocity();
    v.x = speed;
    playerCharacter.SetVelocity(v);
}else if(IsKeyDown(KEY_LEFT))
{
    Vector2 v = playerCharacter.GetVelocity();
    v.x = -speed;
    playerCharacter.SetVelocity(v);
}else
{
    Vector2 v = playerCharacter.GetVelocity();
    v.x = 0;
    playerCharacter.SetVelocity(v);
}


        if (IsKeyDown(KEY_SPACE) && playerCharacter.GetState().isGrounded) // il faut que ce soit une velociter constante pendant un certain temp
        {

    Vector2 v = playerCharacter.GetVelocity();
    v = jumpSpeed;
    playerCharacter.SetVelocity(v);

        }


        BeginDrawing();
        ClearBackground(BACKGROUND);

        BeginMode2D(camera);

        

        r = CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, ground);
        if (CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, ground)) // si la prochaine pose n'overlap pas le rectagle
        {

                Vector2 v = playerCharacter.GetVelocity();
                v.y = 0;
                playerCharacter.SetVelocity(v);
                playerCharacter.SetStateIsGrounded(true);
        }else
        {
            playerCharacter.SetStateIsGrounded(false);
        }
        
        if (CheckCollisionCircles(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, test.GetPosition(), test.GetSize())) 
        {
            playerCharacter.Death();

        }
        
        playerCharacter.ApplyVelocity();
        // std::async(std::launch::async, CheckState);
        // DrawRectangle(-250, -1000, 500 , 1000 , WHITE);
        DrawRectangleRec(area, WHITE);
        DrawRectangleRec(ground, GREEN);
        

        DrawCircle(playerCharacter.GetPosition().x, playerCharacter.GetPosition().y, playerCharacter.TAILLECHARACTER, playerCharacter.GetColor());
        test.DrawEnnemis();
        // DrawCircle(velocity.x, velocity.y, TAILLECHARACTER, CHARACTER);


        
        EndMode2D();
    
        drawUI();
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


void applyGravity(){
    playerCharacter.ADDVelocity(gravity);
}


void drawUI(){
    std::string coX = std::to_string(playerCharacter.GetPosition().x);
        std::string coY = std::to_string(playerCharacter.GetPosition().y);
        std::string veloX = std::to_string(playerCharacter.GetVelocity().x);
        std::string veloY = std::to_string(playerCharacter.GetVelocity().y);
        std::string fullTextCo = "Position : X  : " + coX + " Y : " + coY + " Veclocity : X : " + veloX + " Y : " + veloY;

        std::string GroundedStatus = playerCharacter.GetState().isGrounded ? "grounded" : "in air";

        std::string overlapStatus = r ? "Overlap" : "not overlap";
        std::string fullText = "Print  : " + overlapStatus +  " grounded : " + GroundedStatus;

        DrawText(fullText.c_str(), 10, 10, 30, RED);
        DrawText(fullTextCo.c_str(), 10, 50, 10, YELLOW);
}
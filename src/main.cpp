#include "raylib.h"
#include <string>
#include <future>

Vector2& operator+=(Vector2& a, const Vector2& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2& operator-=(Vector2& a, const Vector2& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2 operator+(Vector2 a, const Vector2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2 operator*(Vector2 a, const float b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

constexpr Color BACKGROUND = BLUE;
constexpr Color CHARACTER = PURPLE;
constexpr int TAILLECHARACTER = 20;
constexpr int SCREENWIDTH = 1540;
constexpr int SCREENHEIGHT = 990;

int characterX = 10;
int characterY = 12;

int speed = 300;
int jumpHeigh = 20;
Vector2 jumpSpeed = {0,550};
Vector2 slowdowGravityAfterFallFromJump = {0,1};
int playerheightBeforeJump;
float slowdownDuration = 0.5;

float timerSlowDown = 0.0f;


Vector2 gravity = {0,100};

Vector2 velocity = gravity;
Vector2 playerPos = {10 , 12};
Vector2 positionCible;
bool grounded = false;
bool inJump = false;
bool startFallFromJump = false;

Camera2D camera;
Rectangle rect = { -2500, 200, 5000, 10 };
float deltaTime;

int main()
{



    
    
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Raylib jeu de la vie");
    SetTargetFPS(60);

    // Initialisation caméra
    camera.target = { (float)characterX, (float)characterY };
    camera.offset = { SCREENWIDTH / 2.0f, SCREENHEIGHT / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        
        deltaTime = GetFrameTime();

        if (!grounded)
        {
            velocity = gravity*deltaTime;
        }
        
        if (inJump)
        {
            velocity -= jumpSpeed * deltaTime;
        }

        if (startFallFromJump)
        {
            velocity -= slowdowGravityAfterFallFromJump * deltaTime;
        }

        
        // Déplacement joueur
        if (IsKeyDown(KEY_RIGHT))
        {
            if (grounded)
            {
                velocity.y =0;
            }
            velocity.x =+ speed * deltaTime;
            // characterX+= speed;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            if (grounded)
            {
                velocity.y = 0;
            }
            
            velocity.x =- speed * deltaTime;
            // characterX-= speed;
        }

        // if (IsKeyDown(KEY_UP))
        // {
        //     velocity.y = gravity.y - speed;
        //     // characterY-= speed; // Monter
        // }

        // if (IsKeyDown(KEY_DOWN))
        // {
        //     velocity.y = gravity.y + speed;
        //     // characterY+= speed; // Descendre
        // }

        if (IsKeyDown(KEY_SPACE) && grounded) // il faut que ce soit une velociter constante pendant un certain temp
        {
            playerheightBeforeJump = playerPos.y * deltaTime;
            inJump = true;
            // velocity.y = gravity.y - jumpForce;
            // characterY-= speed; // Monter
        }

        
        

        // La caméra suit le personnage
        // camera.target = { (float)characterX, (float)characterY };

        BeginDrawing();
        ClearBackground(BACKGROUND);

        BeginMode2D(camera);

        

        // characterX += velocity.x;
        // characterY += velocity.y;
        positionCible = playerPos + velocity;
        bool r = CheckCollisionCircleRec(positionCible, TAILLECHARACTER, rect);
        if (!CheckCollisionCircleRec(positionCible, TAILLECHARACTER + 1, rect)) // si la prochaine pose n'overlap pas le rectagle
        {
            playerPos += velocity;
            if (grounded)
            {
                grounded = false;
            }
        }else
        {
            if (!grounded)
            {
                grounded = true;
            }
            
        }

        if (playerPos.y <= playerheightBeforeJump - jumpHeigh )
        {
            inJump = false;
            startFallFromJump = true;
        }
        if (startFallFromJump)
        {
            timerSlowDown += GetFrameTime();
        }
        
        
    
        if (timerSlowDown >= slowdownDuration)
    {
        startFallFromJump = false;
        timerSlowDown = 0;
    }
        
        

        // std::async(std::launch::async, CheckState);
        
        DrawCircle(playerPos.x, playerPos.y, TAILLECHARACTER, CHARACTER);
        // DrawCircle(velocity.x, velocity.y, TAILLECHARACTER, CHARACTER);

        //  DrawRectangle(-250, 200, 500 , 10 , GREEN);
        DrawRectangleRec(rect, GREEN);
        
        EndMode2D();
        std::string coX = std::to_string(playerPos.x);
        std::string coY = std::to_string(playerPos.y);
        std::string veloX = std::to_string(velocity.x);
        std::string veloY = std::to_string(velocity.y);
        std::string fullTextCo = "Position : X  : " + coX + " Y : " + coY + " Veclocity : X : " + veloX + " Y : " + veloY;

        std::string GroundedStatus = grounded ? "grounded" : "in air";
        std::string JumpStatus = inJump ? "en jump" : "Pas en jump";
        std::string overlapStatus = r ? "Overlap" : "not overlap";
        std::string fullText = "Print  : " + overlapStatus + " jump = " + JumpStatus + " grounded : " + GroundedStatus;
        DrawText(fullText.c_str(), 10, 10, 30, RED);
        DrawText(fullTextCo.c_str(), 10, 50, 10, YELLOW);

        // DrawText("TEXT" + r, 10, 10, 30, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

 void  CheckState(){

}
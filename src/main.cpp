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


class player
{
   struct State
   {
    bool isGrounded;
   };

private:
        // position dans la map
     Vector2 position;
    // vitesse qu'a le joueur
    Vector2 velocity;
   State state;
   Color COLOR = { 128, 0, 128, 255 };


public:
    player();
    ~player();
static const int TAILLECHARACTER = 20;
    // --- Position ---
    Vector2 GetPosition()
    {
        return position;
    }
    void SetPosition(Vector2 newPosition)
    {
        position = newPosition;
    }

        void ApplyVelocity()
    {
        position += velocity * GetFrameTime();
    }
    Vector2 GetFuturePosition(){
        return position + velocity * GetFrameTime();
    }

    // --- Velocity ---
    Vector2 GetVelocity()
    {
        return velocity;
    }
    void SetVelocity(Vector2 newVelocity)
    {
        velocity = newVelocity;
    }

    void ADDVelocity(Vector2 addedValue) 
    {
        velocity += addedValue;
    }
    void SubtractVelocity(Vector2 subtrackValue)  
    {
        velocity -= subtrackValue;
    }

    // --- State ---
    State GetState()
    {
        return state;
    }
    void SetState(State newState)
    {
        state = newState;
    }
        void SetStateIsGrounded(bool newState)
    {
        state.isGrounded = newState;
    }

        Color GetColor()
    {
        return COLOR;
    }
};



player::player()
{
position = {10 , 12};
velocity = {0,0};
}

player::~player()
{


}


constexpr Color BACKGROUND = DARKBLUE;
constexpr int SCREENWIDTH = 1540;
constexpr int SCREENHEIGHT = 990;

player playerCharacter;

float speed = 500.5;
Vector2 jumpSpeed = {0,-800}; 
Vector2 gravity = {0,25};

Camera2D camera;
Rectangle rect = { -2500, 200, 5000, 10 };
float deltaTime;



void applyGravity();



int main()
{


    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Raylib jeu de la vie");
    SetTargetFPS(60);
    playerCharacter = player();

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

        

        bool r = CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, rect);
        if (CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, rect)) // si la prochaine pose n'overlap pas le rectagle
        {

                Vector2 v = playerCharacter.GetVelocity();
                v.y = 0;
                playerCharacter.SetVelocity(v);
                playerCharacter.SetStateIsGrounded(true);
        }else
        {
            playerCharacter.SetStateIsGrounded(false);
        }
        


        
        
    

        
        playerCharacter.ApplyVelocity();
        // std::async(std::launch::async, CheckState);
        
        DrawCircle(playerCharacter.GetPosition().x, playerCharacter.GetPosition().y, playerCharacter.TAILLECHARACTER, playerCharacter.GetColor());
        // DrawCircle(velocity.x, velocity.y, TAILLECHARACTER, CHARACTER);

        //  DrawRectangle(-250, 200, 500 , 10 , GREEN);
        DrawRectangleRec(rect, GREEN);
        
        EndMode2D();
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

        // DrawText("TEXT" + r, 10, 10, 30, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


void applyGravity(){
    playerCharacter.ADDVelocity(gravity);
}
#include "raylib.h"
#include "player.h"
#include "utils.h"
#include "ennemis.h"
#include "spawner.h"


constexpr Color BACKGROUND = DARKBLUE;
constexpr int SCREENWIDTH = 1540;
constexpr int SCREENHEIGHT = 990;
constexpr Vector2 SPAWNPOINT = {10 , 12};
player playerCharacter(SPAWNPOINT); // zone de spawn ennemis {250 , -550} {-260 , -550}

float speed = 500.5;
Vector2 jumpSpeed = {0,-800}; 
Vector2 gravity = {0,25};

bool r;
Camera2D camera;
Rectangle ground = { -2500, 200, 5000, 10 }; //         DrawRectangle(-250, -1000, 500 , 1000 , WHITE);
Rectangle wallLeft = { 250, -2500, 10, 5000 }; // (int posX, int posY, int width, int height); 
Rectangle testLeft = { 250, -250, 20, 20 };
Rectangle test3Left = { 260, -240, 5, 5 };
Rectangle test2Left = { 220, -270, 20, 20 };
Rectangle wallRight = { -260, -2500, 10, 5000 };
Rectangle area = { -250, -800, 500 , 1000  }; // playerCharacter.ApplyVelocity(area.x + playerCharacter.TAILLECHARACTER / 2 , area.x + area.width - playerCharacter.TAILLECHARACTER / 2);

std::array<Rectangle*, 3> limiteMap{&ground,&wallLeft,&wallRight};


Vector2 centerPointRec;

std::vector<ennemis> listeEnnemis;
std::vector<ennemis> closeEnnemis;
ennemis test;
spawner spawnerPrincipal;

int limiteMapGauche{area.x};
int limiteMapDroite{area.x + area.width};

float deltaTime;

void applyGravity();
void drawUI();
Vector2 GetCenterPoint(const Rectangle& r);


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
    test.SetPosition({-100 , -550});
    spawnerPrincipal = spawner();


    listeEnnemis.push_back(test);

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

        spawnerPrincipal.timer += deltaTime;

if (spawnerPrincipal.timer >= spawnerPrincipal.delaySpawn) {
    listeEnnemis.push_back(spawnerPrincipal.spawnEnnemy());
    spawnerPrincipal.timer = 0;
}


        BeginDrawing();
        ClearBackground(BACKGROUND);

        BeginMode2D(camera);


        for (size_t i = 0; i < listeEnnemis.size(); i++)
        {
            
for (size_t y = 0; y < limiteMap.size(); y++)
{
        if (CheckCollisionCircleRec(listeEnnemis[i].GetFuturePosition(), listeEnnemis[i].GetSize() + 1, *limiteMap[y]) && listeEnnemis[i].dernierObstacleRebond != limiteMap[y]) // si la prochaine pose n'overlap pas le rectagle
        {
            // if (limiteMap[y] == &ground)
            // {
            //     std::cout << "overlap groud "  << std::endl;
            // }
            // if (limiteMap[y] == &wallLeft)
            // {
            //     std::cout << "overlap wall left "  << std::endl;
            // }
            // if (limiteMap[y] == &wallRight)
            // {
            //     std::cout << "overlap wall right "  << std::endl;
            // }

            listeEnnemis[i].dernierObstacleRebond = limiteMap[y];
            // von récup le millieu du rectangle et on vérifie si il est pas exemple plus haut que le centre plus la longueur/2 voir si il est au dessu
            centerPointRec = GetCenterPoint(*limiteMap[y]); 
/**
 *             width = largeur / horizontal / X| heigh = hauter / vertical / Y
            X moin = gauche | x plus = droite | y moin = haut | y plus = bas | (0, 0) = coin en haut à gauche
            centerPointRec.y + limiteMap[i].height/2; face du dessu
            centerPointRec.y - limiteMap[i].height/2;  face du dessou

            centerPointRec.x + limiteMap[i].width/2; face a droite
            centerPointRec.x - limiteMap[i].width/2; face a gauche
 */
            if (listeEnnemis[i].GetFuturePosition().y > centerPointRec.y + (*limiteMap[y]).height/2) // il rebondi sur le dessous du rectangle
            {
                std::cout << "il rebondi sur le dessoooous du rectangle "  << std::endl;
                if (listeEnnemis[i].GetDir() == direction::HautDroite)
                {
                    listeEnnemis[i].Rebond(direction::BasDroite);
                }
                else if (listeEnnemis[i].GetDir() == direction::HautFauche)
                {
                    listeEnnemis[i].Rebond(direction::BasGauche);
                }

            }
            else if (listeEnnemis[i].GetFuturePosition().y < centerPointRec.y - (*limiteMap[y]).height/2)// il rebondi sur le dessus du rectangle
            {
                std::cout << "il rebondi sur le dessus du rectangle "  << std::endl;
                if (listeEnnemis[i].GetDir() == direction::BasDroite)
                {
                    listeEnnemis[i].Rebond(direction::HautDroite);
                }
                else if (listeEnnemis[i].GetDir() == direction::BasGauche)
                {
                    listeEnnemis[i].Rebond(direction::HautFauche);
                }

                
            }else if (listeEnnemis[i].GetFuturePosition().x > centerPointRec.x + (*limiteMap[y]).width/2) // il rebondi sur le coté droit du rectangle
            {
                std::cout << "il rebondi sur le coté droit du rectangle "  << std::endl;
                if (listeEnnemis[i].GetDir() == direction::BasGauche)
                {
                    listeEnnemis[i].Rebond(direction::BasDroite);
                }
                else if (listeEnnemis[i].GetDir() == direction::HautFauche)
                {
                    listeEnnemis[i].Rebond(direction::HautDroite);
                }
            }else if (listeEnnemis[i].GetFuturePosition().x < centerPointRec.x - (*limiteMap[y]).width/2)// il rebondi sur le coté gauche du rectangle
            {
                std::cout << "il rebondi sur le coté gauche du rectangle "  << std::endl;
                if (listeEnnemis[i].GetDir() == direction::BasDroite)
                {
                    listeEnnemis[i].Rebond(direction::BasGauche);
                }
                else if (listeEnnemis[i].GetDir() == direction:: HautDroite)
                {
                    listeEnnemis[i].Rebond(direction::HautFauche);
                }
            }

            
                
        }
        listeEnnemis[i].ApplyVelocity();
}

        }
        
        playerCharacter.ApplyVelocity();

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
        
        
        // std::async(std::launch::async, CheckState);
        // DrawRectangle(-250, -1000, 500 , 1000 , WHITE);
        DrawRectangleRec(area, WHITE);
        DrawRectangleRec(ground, GREEN);
        DrawRectangleRec(wallLeft, ORANGE);
        DrawRectangleRec(wallRight, PINK);
        DrawRectangleRec(testLeft, PURPLE); // test2Left
        DrawRectangleRec(test2Left, YELLOW);// test3Left
        DrawRectangleRec(test3Left, RED);
        



        DrawCircle(playerCharacter.GetPosition().x, playerCharacter.GetPosition().y, playerCharacter.TAILLECHARACTER, playerCharacter.GetColor());

        for (size_t i = 0; i < listeEnnemis.size(); i++)
        {
            listeEnnemis[i].DrawEnnemis();
           std::array<Vector2,8> r = octogone(listeEnnemis[i].GetPosition(),listeEnnemis[i].GetSize()).getOctogonePoints();
           for (size_t w = 0; w < r.size(); w++)
           {
                DrawCircle(r[w].x,r[w].y, 5 , BLACK);
           }
           
        }

     
        // DrawCircle(velocity.x, velocity.y, TAILLECHARACTER, CHARACTER);


        
        EndMode2D();
    
        drawUI();
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


void applyGravity(){
    if (!playerCharacter.GetState().isGrounded)
    {
        playerCharacter.ADDVelocity(gravity);
    }
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

Vector2 GetCenterPoint(const Rectangle& r){
    return {r.x + r.width * 0.5f, r.y + r.height * 0.5f};
}
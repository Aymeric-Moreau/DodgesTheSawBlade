#include "inMainGameState.h"

inMainGameState::inMainGameState(/* args */)
{
}

inMainGameState::~inMainGameState()
{
}

    void inMainGameState::initState(){
        startMainGame();
    }
    void inMainGameState::updateLogic(){
                        applyGravity();
                playerCharacter.checkPlayerController();
                spawnerManager();
                ennemisUpdate();
                playerUpdate();
    }
    void inMainGameState::updateDraw(){
        drawMainGame();
    }


    void inMainGameState::startMainGame()
{
    playerCharacter = player(SPAWNPOINT); // playerCharacter.ApplyVelocity(area.x + playerCharacter.TAILLECHARACTER / 2 , area.x + area.width - playerCharacter.TAILLECHARACTER / 2);
    playerCharacter.SetLimiteMap(limiteMapGauche, limiteMapDroite);
    // Initialisation caméra
    camera.target = {playerCharacter.GetPosition().x, playerCharacter.GetPosition().y};
    camera.offset = { gM.SCREENWIDTH / 2.0f, gM.SCREENHEIGHT / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    // test.SetPosition({-100, -550});
    spawnerPrincipal = spawner();
}

void inMainGameState::applyGravity()
{
    if (!playerCharacter.GetState().isGrounded)
    {
        playerCharacter.ADDVelocity(gravity);
    }
}

void inMainGameState::playerInput()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        Vector2 v = playerCharacter.GetVelocity();
        v.x = speed;
        playerCharacter.SetVelocity(v);
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        Vector2 v = playerCharacter.GetVelocity();
        v.x = -speed;
        playerCharacter.SetVelocity(v);
    }
    else
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
}

void inMainGameState::ennemisUpdate()
{
    for (size_t i = 0; i < listeEnnemis.size(); i++)
    {

        if (CheckCollisionCircles(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, listeEnnemis[i].GetPosition(), listeEnnemis[i].GetSize()))
        {
            playerCharacter.Death();
        }

        for (size_t y = 0; y < limiteMap2.size(); y++)
        {
            bool collisionNow = CheckCollisionCircleRec(
                listeEnnemis[i].GetPosition(),
                listeEnnemis[i].GetSize() + 1,
                limiteMap2[y]->GetMain());

            bool collisionNext = CheckCollisionCircleRec(
                listeEnnemis[i].GetFuturePosition(),
                listeEnnemis[i].GetSize() + 1,
                limiteMap2[y]->GetMain());
            if ((collisionNow || collisionNext) && listeEnnemis[i].dernierObstacleRebond != limiteMap2[y]) // si la prochaine pose n'overlap pas le rectagle
            {
                // if (limiteMap[y] == &ground)
                // {
                //     std::cout << "overlap groud "  << std::endl;
                // }
                // if (limiteMap[y] == &wallRight)
                // {
                //     std::cout << "overlap wall left "  << std::endl;
                // }
                // if (limiteMap[y] == &wallLefts)
                // {
                //     std::cout << "overlap wall right "  << std::endl;
                // }

                listeEnnemis[i].dernierObstacleRebond = limiteMap2[y];
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
                if (CheckCollisionCircleRec(
                        listeEnnemis[i].GetPosition(),
                        listeEnnemis[i].GetSize() + 1,
                        limiteMap2[y]->GetBas())) // il rebondi sur le dessous du rectangle  listeEnnemis[i].GetPosition().y > centerPointRec.y + (*limiteMap[y]).height/2
                {
                    listeEnnemis[i].nbrRebond++;
                    std::cout << "il rebondi sur le dessoooous du rectangle " << std::endl;
                    if (listeEnnemis[i].GetDir() == direction::HautDroite)
                    {
                        listeEnnemis[i].Rebond(direction::BasDroite);
                    }
                    else if (listeEnnemis[i].GetDir() == direction::HautFauche)
                    {
                        listeEnnemis[i].Rebond(direction::BasGauche);
                    }
                }
                else if (CheckCollisionCircleRec(
                             listeEnnemis[i].GetPosition(),
                             listeEnnemis[i].GetSize() + 1,
                             limiteMap2[y]->GetGauche())) // il rebondi sur le coté gauche du rectangle
                {
                    listeEnnemis[i].nbrRebond++;
                    std::cout << "il rebondi sur le coté gauche du rectangle " << std::endl;
                    if (listeEnnemis[i].GetDir() == direction::BasDroite)
                    {
                        listeEnnemis[i].Rebond(direction::BasGauche);
                    }
                    else if (listeEnnemis[i].GetDir() == direction::HautDroite)
                    {
                        listeEnnemis[i].Rebond(direction::HautFauche);
                    }
                }
                else if (CheckCollisionCircleRec(
                             listeEnnemis[i].GetPosition(),
                             listeEnnemis[i].GetSize() + 1,
                             limiteMap2[y]->GetHaut())) // il rebondi sur le dessus du rectangle
                {
                    listeEnnemis[i].nbrRebond++;
                    std::cout << "il rebondi sur le dessus du rectangle " << std::endl;
                    if (listeEnnemis[i].GetDir() == direction::BasDroite)
                    {
                        listeEnnemis[i].Rebond(direction::HautDroite);
                    }
                    else if (listeEnnemis[i].GetDir() == direction::BasGauche)
                    {
                        listeEnnemis[i].Rebond(direction::HautFauche);
                    }
                }
                else if (CheckCollisionCircleRec(
                             listeEnnemis[i].GetPosition(),
                             listeEnnemis[i].GetSize() + 1,
                             limiteMap2[y]->GetDroite())) // il rebondi sur le coté droit du rectangle
                {
                    listeEnnemis[i].nbrRebond++;
                    std::cout << "il rebondi sur le coté droit du rectangle " << std::endl;
                    if (listeEnnemis[i].GetDir() == direction::BasGauche)
                    {
                        listeEnnemis[i].Rebond(direction::BasDroite);
                    }
                    else if (listeEnnemis[i].GetDir() == direction::HautFauche)
                    {
                        listeEnnemis[i].Rebond(direction::HautDroite);
                    }
                }
            }
        }
        listeEnnemis[i].ApplyVelocity();
    }
}

void inMainGameState::drawUI()
{
    std::string coX = std::to_string(playerCharacter.GetPosition().x);
    std::string coY = std::to_string(playerCharacter.GetPosition().y);
    std::string veloX = std::to_string(playerCharacter.GetVelocity().x);
    std::string veloY = std::to_string(playerCharacter.GetVelocity().y);
    std::string fullTextCo = "Position : X  : " + coX + " Y : " + coY + " Veclocity : X : " + veloX + " Y : " + veloY;

    std::string GroundedStatus = playerCharacter.GetState().isGrounded ? "grounded" : "in air";

    std::string overlapStatus = r ? "Overlap" : "not overlap";
    std::string fullText = "Print  : " + overlapStatus + " grounded : " + GroundedStatus;

    DrawText(fullText.c_str(), 10, 10, 30, RED);
    DrawText(fullTextCo.c_str(), 10, 50, 10, YELLOW);
}

Vector2 GetCenterPoint(const Rectangle &r)
{
    return {r.x + r.width * 0.5f, r.y + r.height * 0.5f};
}

void inMainGameState::debugEnnemis(int i)
{

    std::string dernierColStatu = listeEnnemis[i].dernierObstacleRebond == limiteMap2[2] ? " der : 2" : "der not = 2";

    Vector2 pos = listeEnnemis[i].GetPosition();
    Vector2 fpos = listeEnnemis[i].GetFuturePosition();
    Vector2 vel = listeEnnemis[i].GetVelocity();

    // collisions avec chaque mur
    bool colG = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize() + 1, ground);
    bool colR = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize() + 1, wallRight);
    bool colL = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize() + 1, wallLefts);

    // dernier obstacle
    std::string last = "none";
    if (listeEnnemis[i].dernierObstacleRebond == &ground2)
        last = "ground";
    if (listeEnnemis[i].dernierObstacleRebond == &wallRight2)
        last = "right";
    if (listeEnnemis[i].dernierObstacleRebond == &wallLefts2)
        last = "left";

    // lignes de debug
    std::string l1 = "Pos: " + std::to_string((int)pos.x) + "," + std::to_string((int)pos.y);
    std::string l2 = "Fpos: " + std::to_string((int)fpos.x) + "," + std::to_string((int)fpos.y);
    std::string l3 = "Velo: " + std::to_string((int)vel.x) + "," + std::to_string((int)vel.y);
    std::string l4 = "G:" + std::to_string(colG) + " L:" + std::to_string(colL) + " R:" + std::to_string(colR);
    std::string l5 = "lastCol: " + last + " nbr rebond : " + std::to_string(listeEnnemis[i].nbrRebond);
    std::string l6 = "Dir: " + DirToString(listeEnnemis[i].GetDir());
    // affichage compact
    int drawX = pos.x;
    int drawY = pos.y;

    std::string debugCollision = "";

    for (size_t j = 0; j < limiteMap2.size(); j++)
    {
        obstacle *obs = limiteMap2[j];

        bool cH = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize(), obs->GetHaut());
        bool cB = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize(), obs->GetBas());
        bool cG = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize(), obs->GetGauche());
        bool cD = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize(), obs->GetDroite());
        bool cMain = CheckCollisionCircleRec(fpos, listeEnnemis[i].GetSize(), obs->GetMain());

        debugCollision += "Obs" + std::to_string(j) + " ";
        debugCollision += "[M:" + std::to_string(cMain);
        debugCollision += " H:" + std::to_string(cH);
        debugCollision += " B:" + std::to_string(cB);
        debugCollision += " G:" + std::to_string(cG);
        debugCollision += " D:" + std::to_string(cD) + "] ";
    }

    // affichage propre
    DrawText(l1.c_str(), drawX, drawY, 10, PURPLE);
    DrawText(l2.c_str(), drawX, drawY + 12, 10, PURPLE);
    DrawText(l3.c_str(), drawX, drawY + 24, 10, PURPLE);
    DrawText(l4.c_str(), drawX, drawY + 36, 10, PURPLE);
    DrawText(l5.c_str(), drawX, drawY + 48, 10, PURPLE);
    DrawText(l6.c_str(), drawX, drawY + 60, 10, ORANGE);
    DrawText(debugCollision.c_str(), drawX, drawY + 72, 10, RED);
    std::array<Vector2, 8> r = octogone(listeEnnemis[i].GetPosition(), listeEnnemis[i].GetSize()).getOctogonePoints();
    for (size_t w = 0; w < r.size(); w++)
    {
        DrawCircle(r[w].x, r[w].y, 5, BLACK);
    }
}

void inMainGameState::spawnerManager()
{

    spawnerPrincipal.timer += deltaTime;

    if (spawnerPrincipal.timer >= spawnerPrincipal.delaySpawn)
    {
        listeEnnemis.push_back(spawnerPrincipal.spawnEnnemy());
        spawnerPrincipal.timer = 0;
    }
}

void inMainGameState::playerUpdate()
{
    playerCharacter.ApplyVelocity();

    r = CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, ground);
    if (CheckCollisionCircleRec(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, ground)) // si la prochaine pose n'overlap pas le rectagle
    {

        Vector2 v = playerCharacter.GetVelocity();
        v.y = 0;
        playerCharacter.SetVelocity(v);
        playerCharacter.SetStateIsGrounded(true);
    }
    else
    {
        playerCharacter.SetStateIsGrounded(false);
    }

    if (CheckCollisionCircles(playerCharacter.GetFuturePosition(), playerCharacter.TAILLECHARACTER + 1, test.GetPosition(), test.GetSize()))
    {
        playerCharacter.Death();
    }
}

void inMainGameState::drawMainGame()
{
    // std::async(std::launch::async, CheckState);
    // DrawRectangle(-250, -1000, 500 , 1000 , WHITE);
    DrawRectangleRec(area, WHITE);
    DrawRectangleRec(ground2.GetMain(), GREEN);
    DrawRectangleRec(wallRight2.GetMain(), ORANGE);
    DrawRectangleRec(wallLefts2.GetMain(), PINK);

    for (size_t y = 0; y < limiteMap2.size(); y++)
    {
        obstacle *obs = limiteMap2[y];

        DrawRectangleRec(obs->GetHaut(), GREEN);
        DrawRectangleRec(obs->GetBas(), YELLOW);
        DrawRectangleRec(obs->GetGauche(), BLUE);
        DrawRectangleRec(obs->GetDroite(), RED);
    }

    DrawCircle(playerCharacter.GetPosition().x, playerCharacter.GetPosition().y, playerCharacter.TAILLECHARACTER, playerCharacter.GetColor());

    for (size_t i = 0; i < listeEnnemis.size(); i++)
    {
        listeEnnemis[i].DrawEnnemis();

        // listeEnnemis[i].dernierObstacleRebond == limiteMap[y]
        debugEnnemis(i);
    }

    // DrawCircle(velocity.x, velocity.y, TAILLECHARACTER, CHARACTER);
}

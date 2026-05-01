#pragma once
#include "raylib.h" 
#include "raymath.h"
#include <cmath>
#include <string>
#include <future>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>

#include <vector>
#include <array>
// #include "C:/raylib/include/raymath.h"

struct octogone
{
    Vector2 coDroite;
    Vector2 coHautDroite;
    Vector2 coHaut;
    Vector2 coHautGauche;
    Vector2 coGauche;
    Vector2 cobasGauche;
    Vector2 coBas;
    Vector2 coBasDroite;
 // Point(int x_val, int y_val) : x(x_val), y(y_val) {}
octogone(Vector2 co, float radius)
    : coDroite     ({co.x + cos(0.0f)        * radius, co.y - sin(0.0f)        * radius}),
      coHautDroite ({co.x + cos(PI/4)     * radius, co.y - sin(PI/4)     * radius}),
      coHaut       ({co.x + cos(PI/2)     * radius, co.y - sin(PI/2)     * radius}),
      coHautGauche ({co.x + cos(3*PI/4)   * radius, co.y - sin(3*PI/4)   * radius}),
      coGauche     ({co.x + cos(PI)       * radius, co.y - sin(PI)       * radius}),
      cobasGauche  ({co.x + cos(5*PI/4)   * radius, co.y - sin(5*PI/4)   * radius}),
      coBas        ({co.x + cos(3*PI/2)   * radius, co.y - sin(3*PI/2)   * radius}),
      coBasDroite  ({co.x + cos(7*PI/4)   * radius, co.y - sin(7*PI/4)   * radius})
{}
    // octogone getoctogoneFromCircle(Vector2 co,float radius){

    // }

    std::array<Vector2,8> getOctogonePoints(){
         std::array<Vector2,8> r{  coDroite,
     coHautDroite,
     coHaut,
     coHautGauche,
     coGauche,
     cobasGauche,
     coBas,
     coBasDroite};
     return r;
    }
};


    const Vector2 BASDROITE = {1 , 1};
    const Vector2 BASGAUCHE = {-1 , 1};
    const Vector2 HAUTDROITE = {1 , -1};
    const Vector2 HAUTGAUCHE = {-1 , -1};

    enum direction{BasDroite,BasGauche,HautDroite,HautFauche};

    enum gameState{MainMenue,PauseMenue,InMainGame,GameOver};

bool HasState( std::vector<gameState> vector ,gameState s );

std::string DirToString(direction dir);
// Vector2& operator+=(Vector2& a, const Vector2& b);
// Vector2& operator-=(Vector2& a, const Vector2& b);
// Vector2 operator+(Vector2 a, const Vector2 b);
// Vector2 operator*(Vector2 a, const float b);
Vector2 MakePositive(Vector2 v);




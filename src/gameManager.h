#pragma once
#include "raylib.h"
#include "utils.h"
#include "state.h"


// Globals.h

struct gameManager
{
Color BACKGROUND = DARKBLUE;
const int SCREENWIDTH = 1540;
const int SCREENHEIGHT = 990;
Camera2D camera;
float deltaTime;
bool stateActive;
bool haveToChangeState = false;
std::unique_ptr<state> StateSuivant = nullptr;
std::vector<std::unique_ptr<state>> activeStates;
void addState(std::unique_ptr<state> newState);
void replaceState(std::unique_ptr<state> newState);
};

// void addState(std::unique_ptr<state> newState);
extern gameManager gM;
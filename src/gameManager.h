#pragma once
#include "raylib.h"
#include "utils.h"
#include "state/state.h"
#include "rini.h"

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
float playerTimer = 0;
int coins = 0;
rini_data config;


void addState(std::unique_ptr<state> newState);
void replaceState(std::unique_ptr<state> newState);


   template <typename T>
    void suppState()
    {
        for (size_t i = 0; i < activeStates.size(); i++)
        {
            if (dynamic_cast<T*>(activeStates[i].get()))
            {
                activeStates.erase(activeStates.begin() + i);
                return;
            }
        }
    }

};
void suppState();
// void addState(std::unique_ptr<state> newState);
extern gameManager gM;
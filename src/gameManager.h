#pragma once
#include "raylib.h"
#include "utils.h"


// Globals.h

struct gameManager
{
Color BACKGROUND = DARKBLUE;
const int SCREENWIDTH = 1540;
const int SCREENHEIGHT = 990;
Camera2D camera;
};
extern gameManager gM;
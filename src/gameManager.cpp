// Globals.cpp
#include "gameManager.h"

gameManager gM;

void gameManager::addState(std::unique_ptr<state> newState){

    activeStates.insert(activeStates.begin(), std::move(newState));

    if (!activeStates.empty())
    {
        activeStates[0]->initState();
    }
}

void gameManager::replaceState(std::unique_ptr<state> newState){

    activeStates.clear();
    activeStates.push_back(std::move(newState));
    // activeStates.insert(activeStates.begin(), std::move(newState));
        std::cout << " replace state\n";
    if (!activeStates.empty())
    {
        activeStates[0]->initState();
    }
}


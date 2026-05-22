// Globals.cpp
#include "gameManager.h"

gameManager gM;

void gameManager::addState(std::unique_ptr<state> newState){

    stateActive = false;

    activeStates.insert(activeStates.begin(), std::move(newState));

    if (!activeStates.empty())
    {
        activeStates[0]->initState();
    }
    stateActive = true;
}

void gameManager::replaceState(std::unique_ptr<state> newState){

    stateActive = false;

    for (auto &&i : activeStates)
    {
        i.reset();
    }
    

    activeStates.clear();
    activeStates.push_back(std::move(newState));
    // activeStates.insert(activeStates.begin(), std::move(newState));
        std::cout << " replace state\n";
    if (!activeStates.empty())
    {
        std::cout << " init state\n";
        activeStates[0]->initState();
    }
    stateActive = true;
}
// template <typename T>
// void suppState()
// {
//     for (size_t i = 0; i < gM.activeStates.size(); i++)
//     {
//         if (dynamic_cast<T*>(gM.activeStates[i].get()))
//         {
//             gM.activeStates.erase(gM.activeStates.begin() + i);
//             return;
//         }
//     }
// }
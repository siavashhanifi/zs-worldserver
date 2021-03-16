#include "Game.h"

zs_worldserver::Game* zs_worldserver::Game::singleton = nullptr;
zs_worldserver::Game* zs_worldserver::Game::getInstance(){
    if(singleton == nullptr)
        singleton = new Game();
    return singleton;
}

zs_worldserver::Game::Game(){
    
}
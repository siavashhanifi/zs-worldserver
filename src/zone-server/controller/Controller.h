#pragma once

#include <thread>
#include "../network/CPSCommunicator.h"
#include "../model/Game.h"
#include "data/Zone.h"
#include "data/PlayerState.h"

namespace zs_worldserver {
    
    class CPSCommunicator;
    
    class Controller {
    public:
        static Controller *singleton;
        static Controller *getInstance();
        void init(Zone zone, std::string ip, int port);
        Status addClient(PlayerState ps);
    private:
        Controller();
        Zone zone;
        CPSCommunicator *cpsCom;
        Game *game;
    };
}
#pragma once

#include "../network/CPSCommunicator.h"
#include "../model/Game.h"
#include "data/Zone.h"

namespace zs_worldserver {
    class Controller {
    public:
        Controller(Zone zone, std::string ip, int port);
    private:
        Zone zone;
        CPSCommunicator *cpsCom;
        Game *game;
    };
}
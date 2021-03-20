#pragma once

#include "data/PlayerState.h"

namespace zs_worldserver {
    class Game {
    public:
        static Game* singleton;
        static Game* getInstance();
        void addPlayer(PlayerState ps);
    private:
        
        Game();
    };
}
#pragma once

namespace zs_worldserver {
    class Game {
    public:
        static Game* singleton;
        static Game* getInstance();
        
    private:
        Game();
    };
}
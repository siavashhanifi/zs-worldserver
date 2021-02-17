#pragma once 
#include<mutex>
#include"../data/Zone.h"

namespace zs_worldserver {
    class ZoneHandler {
     
    public:
        static ZoneHandler *getInstance();
        ~ZoneHandler();
        Zone getStartZone();
    private:
        const int MAX_ZONES = 20;
        static ZoneHandler *singletonZH;
        std::mutex lock;
        Zone startZone;
        Zone *zones;
        ZoneHandler();
    };
}

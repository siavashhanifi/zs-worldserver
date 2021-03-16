#pragma once
#include <unordered_map>
#include <mutex>
#include "../../common/data/Zone.h"

namespace zs_worldserver{
    class Zones {
    public:
        static Zones* zonesSingleton;
        static Zones* getInstance();
        void addZone(Zone zone, int socket);
        Zone getStartZone();
        int getSocket(int zoneId);
    private:
        Zones();
        std::mutex lock;
        std::unordered_map<int, Zone> idZone;
        std::unordered_map<int, int> idSocket;//key:id <-> value:socket
    };
}
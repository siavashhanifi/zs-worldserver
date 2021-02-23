#pragma once
#include <unordered_map>
#include <mutex>
#include "../../common/data/Zone.h"

namespace zs_worldserver{
    class Zones {
    public:
        static Zones* zonesSingleton;
        static Zones* getInstance();
        void addZone(Zone zone);
    private:
        Zones();
        std::mutex lock;
        std::unordered_map<int, Zone> idZone;
    };
}
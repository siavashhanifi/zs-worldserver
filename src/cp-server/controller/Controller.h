#pragma once
#include "../../common/data/Zone.h"
#include "../model/Zones.h"

namespace zs_worldserver {
    class Controller {
    public:
        static Controller* controller;
        static Controller* getInstance();
        void addZone(Zone zone);
    private:
        Controller();
        Zones *zones;
    };
}
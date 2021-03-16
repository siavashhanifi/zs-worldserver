#pragma once

#include <string>
#include "../../common/data/Zone.h"
#include "../model/Zones.h"
#include "../model/Session.h"
#include "../model/ZoneComUtil.h"

namespace zs_worldserver {
    class Controller {
    public:
        static Controller* controller;
        static Controller* getInstance();
        void addZone(Zone zone, int socket);
        Status addClient(std::string name);
    private:
        Controller();
        Zones *zones;
        Session *session;
    };
}
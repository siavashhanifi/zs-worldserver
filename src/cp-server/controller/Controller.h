#pragma once

#include <string>
#include "../model/Zones.h"
#include "../model/Session.h"
#include "../model/ZoneComUtil.h"
#include "data/AddClientDTO.h"
#include "data/Zone.h"

namespace zs_worldserver {
    class Controller {
    public:
        static Controller* controller;
        static Controller* getInstance();
        void addZone(Zone zone, int socket);
        AddClientDTO addClient(std::string name);
        void registerClientAdded(int clientId, int zsSocket);
    private:
        Controller();
        Zones *zones;
        Session *session;
    };
}
#pragma once

#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "marshalling/Message.h"
#include "data/Zone.h"
#include "../model/Game.h"

namespace zs_worldserver {
    class ZSCom {
    public:
        static ZSCom* singleton;
        static ZSCom* getInstance();
        void setZone(Zone);
        void getGameState();
    private:
        ZSCom();
    };
}
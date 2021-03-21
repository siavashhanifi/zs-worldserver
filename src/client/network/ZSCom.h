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
        void connectToZS(Zone zone);
        void readNext();
    private:
        ZSCom();
        Game* game;
        SOCKET connection;
        sockaddr_in zsAddress;
        Message* toSend;
        Message* msgIn;
        void createSocket(Zone);
        void connectSocket();
        void readReply();
        void handleInMsg();
    };
}
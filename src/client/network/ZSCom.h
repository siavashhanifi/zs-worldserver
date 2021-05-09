#pragma once

#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "marshalling/TCP/Message.h"
#include "data/Zone.h"
#include "../model/Game.h"

namespace zs_worldserver {
    class ZSCom {
    public:
        static ZSCom* singleton;
        static ZSCom* getInstance();
        void connectToZS(Zone zone);
        void listenForNextInMsg();
    private:
        ZSCom();
        Game* game;
        SOCKET connection;
        sockaddr_in zsAddress;
        Message* toSend;
        Message* inMsg;
        void createSocket(Zone);
        void connectSocket();
        void readInMsg();
        void handleInMsg();
    };
}
#pragma once

#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "marshalling/UDP/UDPMessageHelper.h"
#include "marshalling/TCP/"
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
        char inAndOutBytes[UDP_MSG_MAX_BYTES];
        void createSocket(Zone);
        void connectSocket();
        void readInMsg();
        void handleInMsg();
    };
}
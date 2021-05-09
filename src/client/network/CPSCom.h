#pragma once

#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "marshalling/TCP/Message.h"
#include "data/CPSAddress.h"
#include "data/AddClientDTO.h"
#include "../model/Game.h"

namespace zs_worldserver {
    class CPSCom {
    public:
        static CPSCom* singleton;
        static CPSCom* getInstance();
        AddClientDTO addClient(std::string name);
        void connectToCPS(CPSAddress cpsAddress);
        void listenForNextInMsg();
    private:
        CPSCom();
        Game* game;
        SOCKET connection;
        sockaddr_in cpsAddress;
        Message* toSend;
        Message* inMsg;
        void createSocket(CPSAddress);
        void connectSocket();
        void readInMsg();
        void handleInMsg();
    };
}
#pragma once

#include <sys/socket.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <errno.h>
#include "../../common/marshalling/Message.h"

namespace zs_worldserver {
    class CPSCommunicator{
    public:
        CPSCommunicator(Zone zone, std::string cpsIp, int cpsPort);
    private:
        int connection;
        std::string cpsIp;
        int cpsPort;
        Zone zone;
        Message *toSend;
        Message *msgIn;
        void createSocket();
        void connectSocket();
        void addToCPS();
    };
}
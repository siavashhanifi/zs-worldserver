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
        static CPSCommunicator *singleton;
        static CPSCommunicator *getInstance();
        void connectToCPS(std::string cpsIp, int cpsPort);
        Status addToCPS(Zone zone);
    private:
        int connection;
        std::string cpsIp;
        int cpsPort;
        Message *toSend;
        Message *msgIn;
        void createSocket();
        void connectSocket();
        void addToCPS();
        void readNext();
    };
}
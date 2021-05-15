#pragma once

#include <sys/socket.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <errno.h>
#include "marshalling/TCP/Message.h"
#include  "../controller/Controller.h"

namespace zs_worldserver {

    class Controller;

    class CPSCommunicator {
    public:
        static CPSCommunicator *singleton;
        static CPSCommunicator *getInstance();
        void connectToCPS(std::string cpsIp, int cpsPort);
        Status addToCPS(Zone zone);
        void readNext();
    private:
        CPSCommunicator();
        Controller *controller;
        int connection;
        std::string cpsIp;
        int cpsPort;
        char inBytes[MSG_MAX_BYTES];
        Message *toSend;
        Message *inMsg;
        void createSocket();
        void connectSocket();
        void addToCPS();
        void handleMessage();
        void sendMessage();
    };
}
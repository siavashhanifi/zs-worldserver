#pragma once

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include "marshalling/TCP/Message.h"
#include "../controller/Controller.h"

namespace zs_worldserver{
    
    class ConnectionHandler{
    public:
        ConnectionHandler(int tcpConnection);
        ~ConnectionHandler();
    private:
        int connection;
        char bytes[MSG_MAX_BYTES];
        Message *inMsg;
        Message *reply;
        Controller  *controller;
        void listenForInMsgs();
        void handleMessage();
        void sendReply();
    };
}
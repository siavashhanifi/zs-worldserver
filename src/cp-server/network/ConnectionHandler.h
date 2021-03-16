#pragma once

#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include "../../common/marshalling/Message.h"
#include "../controller/Controller.h"

namespace zs_worldserver{
    
    class ConnectionHandler{
    public:
        ConnectionHandler(int tcpConnection);
        ~ConnectionHandler();
    private:
        int tcpConnection;
        char bytes[MSG_MAX_BYTES];
        Message *msgIn;
        Message *reply;
        Controller  *controller;
        void readNext();
        void handleMessage();
        void sendReply();
    };
}
#pragma once
#include<sys/socket.h>
#include"../../common/marshalling/Message.h"

namespace zs_worldserver{
    
    class ConnectionHandler{
    public:
        ConnectionHandler(int tcpConnection);
    private:
        int tcpConnection;
        Message message;
        Message reply;
        void readNext();
        void handleMessage();
        void sendReply();
    };
}
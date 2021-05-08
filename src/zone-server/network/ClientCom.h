#pragma once

#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unordered_map>
#include "data/Zone.h"
#include "marshalling/UDP/UDPMessageHelper.h"

namespace zs_worldserver {
    class ClientCom {
    public:
        static ClientCom *singleton;
        static ClientCom *getInstance();
        void init(Zone);
        void readNext();
    private:
        ClientCom();
        Zone zone;
        int sockfd;
        char buffer[UDP_MSG_MAX_BYTES];
        char *inMsg;
        char *outMsg;
        sockaddr_in servaddr, cliaddr;
        void parseInData();

    };
}

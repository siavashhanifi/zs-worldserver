#pragma once 
#include<iostream>
#include <thread>
#include<sys/socket.h>
#include <netinet/in.h>
#include<netinet/tcp.h>

#include"ClientTCPHandler.h"
namespace zs_worldserver {
    class TCPListener{
        public:
            TCPListener(int port);
        private:
            int listenerSocket;
    };       
 }

#pragma once

#include <thread>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "ConnectionHandler.h"

namespace zs_worldserver{
    
    void*connectionThread(void*args);
    
    class TCPListener{
    public:
        TCPListener(int port);
    private:
        int listenerSocket;
        int port;
        void createSocket();
        void bindSocket();
        void socketListen();
        
    };
}
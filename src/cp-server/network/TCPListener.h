#pragma once
#include<sys/socket.h>
#include<thread>

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
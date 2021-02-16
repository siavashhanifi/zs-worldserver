#include <infiniband/ib.h>

#include "TCPListener.h"

using namespace zs_worldserver;

void *startClientHandler(void*args){
    int tcpSocket = *(int*)args;
    ClientTCPHandler *clientHandler = new ClientTCPHandler(tcpSocket);
    delete clientHandler;
    return 0;
}

zs_worldserver::TCPListener::TCPListener(int port){
    std::cout<<"TCPListener: Listening for joining clients at port " << port <<
            std::endl;
    int rc; //return code
    listenerSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in tcpInAddr;
    if (listenerSocket == -1) { 
        throw std::runtime_error("Socket creation failed.\n");
    } 
    
    // assign IP, PORT 
    tcpInAddr.sin_family = AF_INET; 
    tcpInAddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    tcpInAddr.sin_port = htons(port); 
    
     // Binding newly created socket to given IP and verification 
    rc = bind(listenerSocket, (sockaddr*)&tcpInAddr, sizeof(tcpInAddr));
    if(rc != 0)
        throw std::runtime_error("Failed to bind socket to address.");
     
    rc = listen(listenerSocket, 5);
    if(rc != 0)
        throw std::runtime_error("Failed to listen.");
    
    int tcpOutAddrSz = sizeof(sockaddr_in);
    sockaddr_in tcpOutAddr;
    while(true){
        int tcpSocket = accept(listenerSocket, (sockaddr*)&tcpOutAddr,
                (socklen_t*)&tcpOutAddrSz);
        if(tcpSocket < 0)
            continue;
        else{
            using thread = std::thread;
            thread clientHandler = thread(&startClientHandler, &tcpSocket);
            clientHandler.detach();
        }    
    }

}       


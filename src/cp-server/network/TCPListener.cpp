#include "TCPListener.h"

zs_worldserver::TCPListener::TCPListener(int port){
    this->port = port;
    createSocket();
    bindSocket();
    socketListen();
}


void zs_worldserver::TCPListener::createSocket(){
   listenerSocket = socket(AF_INET, SOCK_STREAM, 0);
   if (listenerSocket < 0) 
       throw std::runtime_error("Failed to create socket.");
}

void zs_worldserver::TCPListener::bindSocket(){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    int rc = bind(listenerSocket, (struct sockaddr *) &serverAddress, 
            sizeof(serverAddress));
    if(rc < 0)
        throw std::runtime_error("Failed to bind socket.");
}

void zs_worldserver::TCPListener::socketListen(){
    listen(listenerSocket, 5); 
    sockaddr_in clientAddress;
    socklen_t clilen = sizeof(clientAddress);
    while(true){
        int connection = accept(listenerSocket, (sockaddr*)&clientAddress, 
                &clilen);
        if(connection >= 0){
            std::thread newThread(&connectionThread, &connection);
            newThread.detach();
        }
    }
}

void *zs_worldserver::connectionThread(void*args){
    int connection = *(int*)args;
    auto connectionHandler = new ConnectionHandler(connection);
    delete connectionHandler;
    return 0;
}
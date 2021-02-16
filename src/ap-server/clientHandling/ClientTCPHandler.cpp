#include"ClientTCPHandler.h"

zs_worldserver::ClientTCPHandler::ClientTCPHandler(int tcpSocket){
    this->tcpSocket = tcpSocket;
    activePlayers = activePlayers->getInstance();
    activePlayers->addClient(tcpSocket);
    std::cout<<"ClientTCPHandler: Handling client at socket " <<
            tcpSocket << std::endl;
    
}
#include"ClientTCPHandler.h"

zs_worldserver::ClientTCPHandler::ClientTCPHandler(int tcpSocket){
    this->tcpSocket = tcpSocket;
    activePlayers = activePlayers->getInstance();
    int clientId = activePlayers->addClient(tcpSocket);
    std::cout<<"ClientTCPHandler: Handling client at socket " <<
            tcpSocket << std::endl;
    ZoneHandler *zoneHandler = zoneHandler->getInstance();
    Zone startZone = zoneHandler->getStartZone();
    FirstPayload firstPayload = { clientId, startZone } ;
    std::cout<<"ClientTCPHandler: firstPayload { " << firstPayload.clientId <<
            ", " << firstPayload.startZone.name << std::endl;
    
}
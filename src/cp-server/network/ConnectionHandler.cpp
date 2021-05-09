#include "ConnectionHandler.h"
#include <iostream>

zs_worldserver::ConnectionHandler::ConnectionHandler(int tcpConnection){
    this->connection = tcpConnection;
    controller = controller->getInstance();
    listenForInMsgs();
}

zs_worldserver::ConnectionHandler::~ConnectionHandler(){
    close(connection);
}

void zs_worldserver::ConnectionHandler::listenForInMsgs(){
    while(true){
	recv(connection, bytes, MSG_MAX_BYTES, MSG_WAITALL);
        inMsg = new Message(bytes);
        handleMessage();
        delete inMsg;
    }
}

void zs_worldserver::ConnectionHandler::handleMessage(){
    Head head = inMsg->getHead();
    switch(head){
        case Head::ZCP_ADDZONE_REQ:
        {
            std::cout<<"GET ADDZONE REQ: ";
            Zone zone = inMsg->getZone();
            std::cout<< zone.id << std::endl;
            controller->addZone(zone, connection);
            reply = new Message(Head::CPZ_ADDZONE_RES, Status::OK);
            sendReply();
            delete reply;
            break;
        }case Head::CCP_ADDCLIENT_REQ:
        {
            std::string name = inMsg->getPlayerName();
            AddClientDTO dto = controller->addClient(name);
            reply = new Message(Head::CPC_ADDCLIENT_RES_ONE, dto.status);
            sendReply();
            delete reply;
            reply = new Message(Head::CPC_ADDCLIENT_RES_TWO, dto.playerId);
            sendReply();
            delete reply;
            break;
        }
        default:
            break;
    }
}

void zs_worldserver::ConnectionHandler::sendReply(){
    char *bytes = reply->bytes;
    send(connection, bytes, MSG_MAX_BYTES, 0);
}
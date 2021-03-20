#include "ConnectionHandler.h"

zs_worldserver::ConnectionHandler::ConnectionHandler(int tcpConnection){
    this->tcpConnection = tcpConnection;
    controller = controller->getInstance();
    readNext();
}

zs_worldserver::ConnectionHandler::~ConnectionHandler(){
    close(tcpConnection);
}

void zs_worldserver::ConnectionHandler::readNext(){
    int n = 0;
    while(true){
        n += read(tcpConnection, bytes, MSG_MAX_BYTES);
        if(n  == -1 &&  EBADF)
            break; 
        else if(n < MSG_MAX_BYTES)
            continue;
        msgIn = new Message(bytes);
        handleMessage();
        delete msgIn;
        n = 0;
    }
}

void zs_worldserver::ConnectionHandler::handleMessage(){
    Head head = msgIn->getHead();
    switch(head){
        case Head::ZCP_ADDZONE_REQ:
        {
            Zone zone = msgIn->getZone();
            controller->addZone(zone, tcpConnection);
            reply = new Message(Head::CPZ_ADDZONE_RES, Status::OK);
            sendReply();
            delete reply;
            break;
        }case Head::CCP_ADDCLIENT_REQ:
        {
            std::string name = msgIn->getPlayerName();
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
    send(tcpConnection, bytes, MSG_MAX_BYTES, 0);
}
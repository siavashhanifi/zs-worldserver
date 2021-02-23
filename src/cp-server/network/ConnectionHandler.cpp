#include <sys/socket.h>
#include "ConnectionHandler.h"

zs_worldserver::ConnectionHandler::ConnectionHandler(int tcpConnection){
    this->tcpConnection = tcpConnection;
    controller = controller->getInstance();
    readNext();
}

zs_worldserver::ConnectionHandler::~ConnectionHandler(){
    // close(tcpConnection);
}

void zs_worldserver::ConnectionHandler::readNext(){
    while(true){
        int n = read(tcpConnection, bytes, MSG_MAX_BYTES);
        if(n  == -1 &&  EBADF)
            break; 
        msg = new Message(bytes);
        handleMessage();
        delete msg;
    }
}

void zs_worldserver::ConnectionHandler::handleMessage(){
    Head head = msg->getHead();
    switch(head){
        case Head::ZCP_ADDZONE_REQ:
        {
            Zone zone = msg->getZone();
            controller->addZone(zone);
            reply = new Message(Head::ZCP_ADDZONE_RES, Status::OK);
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
    send(tcpConnection, bytes, strlen(bytes)+ 1, 0);
}
#include <unistd.h>
#include <iostream>
#include "CPSCommunicator.h"

zs_worldserver::CPSCommunicator* zs_worldserver::CPSCommunicator::singleton = nullptr;
zs_worldserver::CPSCommunicator* zs_worldserver::CPSCommunicator::getInstance(){
    if(singleton == nullptr)
        singleton = new CPSCommunicator();
    return singleton;
}

void zs_worldserver::CPSCommunicator::connectToCPS(std::string cpsIp, int cpsPort){
    this->cpsIp = cpsIp;
    this->cpsPort = cpsPort;
    createSocket();
    connectSocket();
}

void zs_worldserver::CPSCommunicator::createSocket(){
    connection = socket(AF_INET, SOCK_STREAM, 0);
    if(connection < 0)
        throw std::runtime_error("Failed to create socket.");
}  

void zs_worldserver::CPSCommunicator::connectSocket(){
    // assign IP, PORT 
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_addr.s_addr = inet_addr(cpsIp.c_str()); 
    serverAddress.sin_port = htons(cpsPort); 
    
    int rc;
    rc = connect(connection,(sockaddr*)&serverAddress, sizeof(serverAddress));
    if(rc == -1)
        throw std::runtime_error("Failed to connect to client placement server.");
}

zs_worldserver::Status zs_worldserver::CPSCommunicator::addToCPS(Zone zone){
    toSend = new Message(Head::ZCP_ADDZONE_REQ, zone);
    char *inBytes = new char[MSG_MAX_BYTES];
    send(connection, toSend->bytes, MSG_MAX_BYTES, 0);
    
    int n = 0;
    while(n < MSG_MAX_BYTES){
        n += read(connection, inBytes, MSG_MAX_BYTES);
    }
    
    msgIn = new Message(inBytes);
    Status status = msgIn->getStatus();
    delete msgIn;
    return status;
}


void zs_worldserver::CPSCommunicator::readNext(){
    
}
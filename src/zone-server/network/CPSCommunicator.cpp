#include <unistd.h>
#include <iostream>
#include "CPSCommunicator.h"

zs_worldserver::CPSCommunicator::CPSCommunicator(Zone zone, std::string cpsIp, int cpsPort){
    this->zone = zone;
    this->cpsIp = cpsIp;
    this->cpsPort = cpsPort;
    createSocket();
    connectSocket();
    addToCPS();
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

void zs_worldserver::CPSCommunicator::addToCPS(){
    toSend = new Message(Head::ZCP_ADDZONE_REQ, zone);
    char *inBytes = new char[MSG_MAX_BYTES];
    send(connection, toSend->bytes, MSG_MAX_BYTES, 0);
    
    int n = 0;
    while(n < MSG_MAX_BYTES){
        n += read(connection, inBytes, MSG_MAX_BYTES);
    }
    
    msgIn = new Message(inBytes);
    std::cout << (char)msgIn->getStatus() << "\n";
}
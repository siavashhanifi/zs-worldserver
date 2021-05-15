#include "ClientCom.h"

zs_worldserver::ClientCom* zs_worldserver::ClientCom::singleton =
        nullptr;

zs_worldserver::ClientCom* zs_worldserver::ClientCom::getInstance(){
    if(singleton == nullptr)
        singleton = new ClientCom();
    return singleton;
}

void zs_worldserver::ClientCom::init(Zone zone){
    this->zone = zone;
    createSocket();
    bindSocket();
}

void zs_worldserver::ClientCom::createSocket(){
        // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if ( sockfd  < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
          
    memset(&zsAddress, 0, sizeof(zsAddress));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    zsAddress.sin_family    = AF_INET; // IPv4
    zsAddress.sin_addr.s_addr = INADDR_ANY;
    zsAddress.sin_port = htons(zone.udpPort);
}

void zs_worldserver::ClientCom::bindSocket(){
    // Bind the socket with the server address
    int rc = bind(sockfd, (sockaddr *)&zsAddress, sizeof(zsAddress));
    if(rc < 0){
        std::cerr<<"Failed to bind UDP socket\n";
        exit(EXIT_FAILURE);
    } 
}

void zs_worldserver::ClientCom::readInMsg(){
    	size_t zsAddrSize = sizeof(zsAddress);
    	recvfrom(sockfd, inAndOutBytes, UDP_MSG_MAX_BYTES, MSG_WAITALL,
                (sockaddr*)&cliaddr, (socklen_t*)&zsAddrSize);
}

void zs_worldserver::ClientCom::handleInMsg(){
    switch(inAndOutBytes[0]){
        case (char)Action::INIT_ACTION: {
            inAndOutBytes[0] = (char)Action::MOVE_UP; //Replace with gamestate
            sendMsg();
        }
        default:
            break;
    }
}

void zs_worldserver::ClientCom::readNext(){
    while(true){
        readInMsg();
        handleInMsg();
    }
}

void zs_worldserver::ClientCom::sendMsg(){
        sendto(sockfd, inAndOutBytes, UDP_MSG_MAX_BYTES, 
        MSG_CONFIRM, (sockaddr *) &cliaddr,
            sizeof(cliaddr));
}

zs_worldserver::ClientCom::ClientCom(){

}
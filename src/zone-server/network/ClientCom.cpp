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
        
    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if ( sockfd  < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
      
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
      
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(zone.udpPort);
      
    // Bind the socket with the server address
    int rc = bind(sockfd, (sockaddr *)&servaddr, sizeof(servaddr));
    if(rc < 0){
        std::cerr<<"Failed to bind UDP socket\n";
        exit(EXIT_FAILURE);
    }
    
}

void zs_worldserver::ClientCom::readNext(){
    int len, n;
  
    len = sizeof(cliaddr);  //len is value/resuslt
  
    n = recvfrom(sockfd, (char *)buffer, 20, 
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                (socklen_t*)&len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)StartEndFlag::START_FLAG, 1, 
        MSG_CONFIRM, (sockaddr *) &cliaddr,
            len);
    printf("Hello message sent.\n"); 
    
}

zs_worldserver::ClientCom::ClientCom(){

}
#include"ActivePlayers.h"

zs_worldserver::ActivePlayers *zs_worldserver::ActivePlayers::singleton = NULL;

//Read about the singleton pattern to understand this better.
zs_worldserver::ActivePlayers * zs_worldserver::ActivePlayers::getInstance(){
    if (singleton == NULL)
        singleton = new ActivePlayers();
    return singleton;
}

zs_worldserver::ActivePlayers::ActivePlayers(){
    idCounter = 0;
}

int zs_worldserver::ActivePlayers::addClient(int tcpSocket){
    const std::lock_guard<std::mutex> lg(lock);
    int newId = generateNewId();
    idSockMap[newId] = tcpSocket;
    std::cout << "Added client, id: " << newId << ", socket: "
            <<  idSockMap[newId] << std::endl;
    return newId; 
}

int zs_worldserver::ActivePlayers::generateNewId(){
    return idCounter++;
}
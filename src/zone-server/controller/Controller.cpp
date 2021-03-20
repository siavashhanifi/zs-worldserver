#include "Controller.h"
#include <iostream>

void cpsComThread(zs_worldserver::CPSCommunicator* cpsCom){
    cpsCom->readNext();
}
zs_worldserver::Controller* zs_worldserver::Controller::singleton 
        = nullptr;
zs_worldserver::Controller* zs_worldserver::Controller::getInstance(){
    if(singleton == nullptr)
        singleton = new Controller();
    return singleton;
}

zs_worldserver::Controller::Controller(){
    
}

void zs_worldserver::Controller::init(Zone zone,std::string ip, int port){
    this->zone = zone;
    game = game->getInstance();
    cpsCom = cpsCom->getInstance();
    cpsCom->connectToCPS(ip, port);
    Status status = cpsCom->addToCPS(zone);
    if(status == Status::OK){
        std::cout << "Successfully added to CPS\n";
        /*std::thread cpsComThrd(cpsComThread, cpsCom);
        cpsComThrd.join();*/
        std::cout << "reading next\n";
        cpsCom->readNext();
    }
}

zs_worldserver::Status zs_worldserver::Controller::addClient(PlayerState ps){
    game->addPlayer(ps);
    Status status = Status::OK;
    return status;
}
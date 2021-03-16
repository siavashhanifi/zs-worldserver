#include "Controller.h"

zs_worldserver::Controller::Controller(Zone zone,std::string ip, int port){
    this->zone = zone;
    game = game->getInstance();
    cpsCom = cpsCom->getInstance();
    cpsCom->connectToCPS(ip, port);
    Status status = cpsCom->addToCPS(zone);
    if(status == Status::OK)
        std::cout << "Successfully added to CPS\n";
}
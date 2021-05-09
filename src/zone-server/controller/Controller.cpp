#include "Controller.h"
#include <iostream>

void cpsComThread(zs_worldserver::CPSCommunicator* cpsCom) {
    cpsCom->readNext();
}

void clientComThread(zs_worldserver::ClientCom* clientCom) {
    clientCom->readNext();
}

zs_worldserver::Controller* zs_worldserver::Controller::singleton
        = nullptr;

zs_worldserver::Controller* zs_worldserver::Controller::getInstance() {
    if (singleton == nullptr)
        singleton = new Controller();
    return singleton;
}

zs_worldserver::Controller::Controller() {

}

void zs_worldserver::Controller::init(Zone zone, std::string ip, int port) {

    this->zone = zone;

    //Get singletons
    game = game->getInstance();
    cpsCom = cpsCom->getInstance();
    clientCom = clientCom->getInstance();

    //Init and create+detach thread for client communication
    clientCom->init(zone);
    std::thread ccthread(clientComThread, clientCom);
    ccthread.detach();

    //Connect and add self to CPS
    cpsCom->connectToCPS(ip, port);
    Status status = cpsCom->addToCPS(zone);

    if (status == Status::OK) {
        std::thread cpsThread(cpsComThread, cpsCom);
        cpsThread.detach();
        while(true);
    }
}

zs_worldserver::Status zs_worldserver::Controller::addClient(PlayerState ps) {
    game->addPlayer(ps);
    Status status = Status::OK;
    return status;
}
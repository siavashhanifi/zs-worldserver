#include "Controller.h"

zs_worldserver::Controller* zs_worldserver::Controller::controller = NULL;

zs_worldserver::Controller *zs_worldserver::Controller::getInstance(){
    if(controller == NULL)
        controller = new Controller();
    return controller;
}

zs_worldserver::Controller::Controller(){
    zones = zones->getInstance();
    session = session->getInstance();
}

void zs_worldserver::Controller::addZone(Zone zone, int socket){
    zones->addZone(zone, socket);
}

zs_worldserver::AddClientDTO zs_worldserver::Controller::addClient(std::string name){
    int clientId = session->generateId();
    Zone startZone = zones->getStartZone();
    int zoneSocket =  zones->getSocket(startZone.id);
    Position startPosition = {startZone.border.xMax/2, startZone.border.yMin/2};
    PlayerState ps = {clientId, startPosition};
    Status status = ZoneComUtil::addClientReq(ps, zoneSocket);
    AddClientDTO dto = { status, clientId };
    return dto;
}

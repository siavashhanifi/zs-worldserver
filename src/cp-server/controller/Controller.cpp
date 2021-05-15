#include "Controller.h"

zs_worldserver::Controller* zs_worldserver::Controller::controller = NULL;

zs_worldserver::Controller *zs_worldserver::Controller::getInstance() {
    if (controller == NULL)
        controller = new Controller();
    return controller;
}

zs_worldserver::Controller::Controller() {
    zones = zones->getInstance();
    session = session->getInstance();
}

void zs_worldserver::Controller::addZone(Zone zone, int socket) {
    zones->addZone(zone, socket);
    std::cout<<"Added zone with id: " << zone.id << " ip: " << zone.ip <<
            " port: " << std::to_string(zone.udpPort) << std::endl;
}

zs_worldserver::AddClientDTO zs_worldserver::Controller::addClient(std::string name) {
    int clientId = session->generateId();
    Zone startZone = zones->getStartZone();

    //Set client start position
    Position startPosition = {startZone.border.xMax / 2, startZone.border.yMin / 2};
    PlayerState ps = {clientId, startPosition};

    //Tell string zone server to add client
    int zoneSocket = zones->getSocket(startZone.id);
    Status status = ZoneComUtil::addClientReq(ps, zoneSocket);

    //Set reply details
    AddClientDTO dto = {status, startZone, clientId};
    return dto;
}
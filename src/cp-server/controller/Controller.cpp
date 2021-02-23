#include "Controller.h"

zs_worldserver::Controller* zs_worldserver::Controller::controller = NULL;

zs_worldserver::Controller *zs_worldserver::Controller::getInstance(){
    if(controller == NULL)
        controller = new Controller();
    return controller;
}

zs_worldserver::Controller::Controller(){
    zones = zones->getInstance();
}

void zs_worldserver::Controller::addZone(Zone zone){
    zones->addZone(zone);
}

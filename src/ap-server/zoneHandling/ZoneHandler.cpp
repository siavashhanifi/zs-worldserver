#include"ZoneHandler.h"

zs_worldserver::ZoneHandler *zs_worldserver::ZoneHandler::singletonZH = NULL;

zs_worldserver::ZoneHandler* zs_worldserver::ZoneHandler::getInstance(){
    if(singletonZH == NULL)
        singletonZH = new ZoneHandler();
    return singletonZH;
}

zs_worldserver::ZoneHandler::ZoneHandler(){
    zones = new Zone[MAX_ZONES];
}

zs_worldserver::ZoneHandler::~ZoneHandler(){
    delete[] zones;
}
zs_worldserver::Zone zs_worldserver::ZoneHandler::getStartZone(){
    Zone startZone = { "localhost", 27020, "StartZone" };
    return startZone;
}
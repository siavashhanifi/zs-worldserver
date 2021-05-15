#include "Zones.h"
#include <iostream>

zs_worldserver::Zones* zs_worldserver::Zones::zonesSingleton = NULL;
zs_worldserver::Zones* zs_worldserver::Zones::getInstance(){
    if(zonesSingleton == NULL)
        zonesSingleton = new Zones();
    return zonesSingleton;
}

zs_worldserver::Zones::Zones(){
   
}

void zs_worldserver::Zones::addZone(Zone zone, int socket){
    const std::lock_guard<std::mutex> lockGuard(lock);
    idZone[zone.id] = zone;
    idSocket[zone.id] = socket;
}

zs_worldserver::Zone zs_worldserver::Zones::getStartZone(){
    return idZone[0];
}

int zs_worldserver::Zones::getSocket(int zoneId){
    return idSocket[zoneId];
}
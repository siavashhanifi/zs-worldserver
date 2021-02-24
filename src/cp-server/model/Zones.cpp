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

void zs_worldserver::Zones::addZone(Zone zone){
    const std::lock_guard<std::mutex> lockGuard(lock);
    idZone[zone.id] = zone;
    std::cout<< "zone.id: " << zone.id << " Zone ip: " << idZone[zone.id].ip << std::endl;
}
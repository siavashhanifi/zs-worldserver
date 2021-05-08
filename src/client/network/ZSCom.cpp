#include "ZSCom.h"

zs_worldserver::ZSCom* zs_worldserver::ZSCom::singleton = nullptr;
zs_worldserver::ZSCom* zs_worldserver::ZSCom::getInstance() {
	if (singleton == nullptr)
		singleton = new ZSCom();
	return singleton;
}

zs_worldserver::ZSCom::ZSCom() {
    
}
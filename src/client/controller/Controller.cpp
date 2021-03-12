#include "Controller.h"

void gfxThread() {
	zs_worldserver::Graphics* gfx = new zs_worldserver::Graphics();
	delete gfx;
}

void cpsComThread(zs_worldserver::CPSCom *cpsCom) {
	
}

zs_worldserver::Controller* zs_worldserver::Controller::singleton = NULL;
zs_worldserver::Controller* zs_worldserver::Controller::getInstance() {
	if (singleton == NULL)
		singleton = new Controller();
	return singleton;
}

zs_worldserver::Controller::Controller() {
	game = game->getInstance();
	cpsCom = cpsCom->getInstance();
	std::thread gfx(&gfxThread);
	gfx.detach();
}

void zs_worldserver::Controller::joinGame(CPSAddress cpsAddress, std::string name) {
	cpsCom->connectToCPS(cpsAddress);
	Status status = cpsCom->addClient(name);
	if (status == Status::OK) {
		std::thread cpsComThread(&cpsComThread, cpsCom);
		cpsComThread.detach();
	}
}
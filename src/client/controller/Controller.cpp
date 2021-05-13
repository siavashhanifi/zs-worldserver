#include "Controller.h"

void gfxThread() {
	zs_worldserver::Graphics* gfx = new zs_worldserver::Graphics();
	delete gfx;
}

void cpsComThread(zs_worldserver::CPSCom *cpsCom) {
	cpsCom->listenForNextInMsg();
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
	zsCom = zsCom->getInstance();
	std::thread gfx(&gfxThread);
	gfx.detach();
}

void zs_worldserver::Controller::joinGame(CPSAddress cpsAddress, std::string name) {
	cpsCom->connectToCPS(cpsAddress);
	AddClientDTO dto = cpsCom->addClient(name);
	std::cout << "got status: " << (char)dto.status << std::endl;
	if (dto.status == Status::OK) {
		std::cout << "Connected!\n";
                std::cout << "Got zone: " << dto.zone.id << " ip: " << dto.zone.ip << "\n";
                std::cout << "port: " << dto.zone.udpPort;
                //zsCom->connect(dto.zone.ip, dto.zone.udpPort);
                game->setPlayerId(dto.playerId);
		std::thread cpsComThread(&cpsComThread, cpsCom);
		cpsComThread.join();
	}
	else
		std::cout << "Failed to connect to CPS";
        while(true); // WAAAAIT
}
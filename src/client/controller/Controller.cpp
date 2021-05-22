#include "Controller.h"

void gfxThread() {
	zs_worldserver::Graphics* gfx = new zs_worldserver::Graphics();
	delete gfx;
}

void cpsComThread(zs_worldserver::CPSCom *cpsCom) {
	cpsCom->listenForNextInMsg();
}

void zsComThread(zs_worldserver::ZSCom* zsCom) {
	zsCom->listenForNextInMsg();
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
	if (dto.status == Status::OK) {
		std::cout << "Connected!\n";
        std::cout << "Got zone: " << dto.zone.id << " ip: " << dto.zone.ip << "\n";
        std::cout << "port: " << dto.zone.udpPort;

		game->setPlayerId(dto.playerId);

        zsCom->init(dto.zone);
		zsCom->sendInitReq();

		/*std::thread zsComThread(&zsComThread, zsCom);
		zsComThread.detach();*/

		std::thread cpsComThread(&cpsComThread, cpsCom);
		cpsComThread.detach();
	}
	else
		std::cout << "Failed to connect to CPS";
        while(true); // WAAAAIT
}
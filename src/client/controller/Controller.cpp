#include "Controller.h"

void gfxThread() {
	zs_worldserver::Graphics* gfx = new zs_worldserver::Graphics();
	delete gfx;
}

void cpsComThread(zs_worldserver::CPSCom *cpsCom) {
	cpsCom->readNext();
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
	AddClientDTO dto = cpsCom->addClient(name);
	if (dto.status == Status::OK) {
		std::cout << "*************GOT ZONE***********\n";
                std::cout << "id: " << dto.zone.id << std::endl;
                std::cout << "ip: " << dto.zone.ip << std::endl;
                std::cout << "port: " << dto.zone.udpPort << std::endl;
                std::cout << "********************************\n";
                std::cout << "********GOT PLAYER ID***********\n";
                std::cout << "player_id: " << dto.playerId << std::endl;
                game->setPlayerId(dto.playerId);
                zsCom.setZone(dto.zone);
                
                std::thread cpsComThread(&cpsComThread, cpsCom);
		cpsComThread.detach();
                
                zsCom.getGameState();
                //zsCom->connect(dto.zone.ip, dto.zone.udpPort);

	}
	else
            std::cout << "Failed to connect to CPS";
        while(true); // WAAAAIT
}
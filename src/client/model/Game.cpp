#include "Game.h"

zs_worldserver::Game* zs_worldserver::Game::singleton = nullptr;
zs_worldserver::Game* zs_worldserver::Game::getInstance() {
	if (singleton == nullptr)
		singleton = new Game();
	return singleton;
}

zs_worldserver::Game::Game() {
	playerState.id = 0;
	playerState.pos.x = 0;
	playerState.pos.y = 0;
}

void zs_worldserver::setPlayerId(int playerId) {
        const std::lock_guard<std::mutex> lockGuard(idLock);
	playerState.id = playerId;
}

void zs_worldserver::setPlayerPos(Position pos){
        const std::lock_guard<std::mutex> lockGuard(posLock);
        playerState.pos = pos;
}
#pragma once

#include <mutex>
#include "data/PlayerState.h"

namespace zs_worldserver {
	class Game {
	public:
		static Game* singleton;
		static Game* getInstance();
        void setPlayerId(int);
        void setPlayerPos(Position);
		PlayerState playerState;
	private:
        std::mutex idLock;
		std::mutex posLock;
		Game();
	};
}
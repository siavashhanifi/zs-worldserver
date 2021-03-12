#pragma once

#include "data/PlayerState.h"

namespace zs_worldserver {
	class Game {
	public:
		static Game* singleton;
		static Game* getInstance();
		PlayerState playerState;
	private:
		Game();
	};
}
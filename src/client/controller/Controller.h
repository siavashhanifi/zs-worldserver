#pragma once

#include <string>
#include <thread>
#include "data/CPSAddress.h"
#include "../model/Game.h"
#include "../network/CPSCom.h"
#include "../view/Graphics.h"

namespace zs_worldserver {
	class Controller {
	public:
		static Controller* singleton;
		static Controller *getInstance();
		void joinGame(CPSAddress, std::string name);
	private:
		Controller();
		Game* game;
		CPSCom* cpsCom;
                ZSCom* zsCom;
	};
}
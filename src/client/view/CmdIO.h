#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "../../common/data/CPSAddress.h"
#include "../controller/Controller.h"

namespace zs_worldserver {
	class CmdIO {
	public:
		CmdIO();
		void queryCPS();
		void queryName();
	private:
		CPSAddress cpsAddress;
		std::string name;
		Controller* controller;
	};
}

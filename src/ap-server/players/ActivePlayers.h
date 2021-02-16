
#pragma once
#include <mutex>
#include<map>
#include<iostream>
#include "../data/Client.h"

namespace zs_worldserver {
	class ActivePlayers {
            public:
		static ActivePlayers* getInstance();
                int addClient(int tcpSocket);
            private:
                static ActivePlayers* singleton;
                std::mutex lock;
                int idCounter;
                std::map<int,int> idSockMap;
                ActivePlayers();
                void mapIdToSocket();
                int generateNewId();
	};
}
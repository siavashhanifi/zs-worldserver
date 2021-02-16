#pragma once
#include<iostream>
#include"../players/ActivePlayers.h"

namespace zs_worldserver {
    class ClientTCPHandler{
    public:
        ClientTCPHandler(int tcpSocket);
    private:
        int tcpSocket;
        ActivePlayers *activePlayers;
    
    };
    
}
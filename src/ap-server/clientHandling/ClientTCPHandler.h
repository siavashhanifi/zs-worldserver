#pragma once
#include<iostream>
#include"../players/ActivePlayers.h"
#include"../zoneHandling/ZoneHandler.h"
#include"../data/FirstPayload.h"

namespace zs_worldserver {
    class ClientTCPHandler{
    public:
        ClientTCPHandler(int tcpSocket);
    private:
        int tcpSocket;
        ActivePlayers *activePlayers;
    
    };
    
}
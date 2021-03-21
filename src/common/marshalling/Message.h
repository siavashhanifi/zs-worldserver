#pragma once

#include <cstring>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include "../data/Zone.h"
#include "../data/Border.h"
#include "../data/Position.h"
#include "../data/PlayerState.h"

namespace zs_worldserver{
    
    enum class Head : char {
        ZCP_ADDZONE_REQ = 'a',
        CPZ_ADDZONE_RES = 'b',
        CCP_ADDCLIENT_REQ = 'c',
        CPZ_ADDCLIENT_REQ = 'd',
        ZCP_ADDCLIENT_RES = 'e',
        CPC_ADDCLIENT_RES_ONE = 'f',
        CPC_ADDCLIENT_RES_TWO = 'g',
        CPC_ADDCLIENT_RES_THREE = 'h'
    };
    
    enum class Status : char {
        OK = 'z',
        FAILED = 'y'
    };

    const int MSG_MAX_BYTES = 128; 
    const int MAX_NAME_LEN = 8;
    
    class Message{
    public:
        char* bytes;
        int size;
        Message(char *bytes);
        Message(Head, Zone);
        Message(Head, Status);
        Message(Head, std::string playerName);
        Message(Head, PlayerState);
        Message(Head, int playerId);
        Head getHead();
        Zone getZone();
        Status getStatus();
        std::string getPlayerName();
        PlayerState getPlayerState();
        int getPlayerId();

    private:
        Head head;
        Zone zone;
        Status status;
        std::string playerName;
        PlayerState playerState;
        int playerId;
       
        /*serialization functions*/
        void serializeHead();
        void serializeZone();
        void serializeStatus();
        void serializeName();
        void serializePlayerState();
        void serializePlayerId();

        void dserializeHead();
        void dserializeZone();
        void dserializeStatus();
        void dserializeName();
        void dserializePlayerState();
        void dserializePlayerId();
        
    };
}

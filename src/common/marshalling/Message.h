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
        CPC_ADDCLIENT_RES = 'f'
    };
    
    enum class Status : char {
        OK = 'z',
        FAILED = 'y'
    };

    const int MSG_MAX_BYTES = sizeof(Head) + sizeof(Zone); 
    const int MAX_NAME_LEN = 8;
    
    class Message{
    public:
        char* bytes;
        int size;
        Message(char *bytes);
        Message(Head, Zone);
        Message(Head, Status);
        Message(Head, std::string);
        Message(Head, PlayerState);
        Head getHead();
        Zone getZone();
        Status getStatus();
        std::string getPlayerName();
        PlayerState getPlayerState();

    private:
        Head head;
        Zone zone;
        Status status;
        std::string playerName;
        PlayerState playerState;
       
        /*serialization functions*/
        void serializeHead();
        void serializeZone();
        void serializeStatus();
        void serializeName();
        void serializePlayerState();

        void dserializeHead();
        void dserializeZone();
        void dserializeStatus();
        void dserializeName();
        void dserializePlayerState();
        
    };
}

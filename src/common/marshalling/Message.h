#pragma once

#include <cstring>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "../data/Zone.h"
#include "../data/Border.h"

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
        Head getHead();
        Zone getZone();
        Status getStatus();
        std::string getPlayerName();
    private:
        Head head;
        Zone zone;
        Status status;
        std::string playerName;
       
        /*serialization functions*/
        void serializeHead();
        void serializeZone();
        void serializeStatus();
        void serializeName();
        void dserializeHead();
        void dserializeZone();
        void dserializeStatus();
        void dserializeName();
        
    };
}
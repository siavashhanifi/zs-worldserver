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
        ZCP_ADDZONE_RES = 'b'
    };
    
    enum class Status : char {
        OK = 'z',
        FAILED = 'y'
    };

    const int MSG_MAX_BYTES = sizeof(Head) + sizeof(Zone);    
    
    class Message{
    public:
        char* bytes;
        int size;
        Message(char *bytes);
        Message(Head, Zone);
        Message(Head, Status);
        Head getHead();
        Zone getZone();
        Status getStatus();
    private:
        Head head;
        Zone zone;
        Status status;
       
        /*serialization functions*/
        void serializeHead();
        void serializeZone();
        void serializeStatus();
        void dserializeHead();
        void dserializeZone();
        void dserializeStatus();
        
    };
}
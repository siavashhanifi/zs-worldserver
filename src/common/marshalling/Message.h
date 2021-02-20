#pragma once
#include"../data/Zone.h"
#include "../data/Status.h"

namespace zs_worldserver{
   
    enum class PayloadType {
        bytes = 0,
        zone = 1,
        status = 2
    };
    
    enum class Head {
        ZCP_ADDZONE_REQ = 0,
        ZCP_ADDZONE_RES = 1
    };
    
    class Message{
    public:
        char* bytes;
        Message(Head, char *bytes);
        Message(Head, Zone);
        Message(Head, Status);
        Head getHead();
        PayloadType getPayloadType();
        Zone getZone();
        Status getStatus();
    private:
        PayloadType type;
        int HEAD;
        Zone zone;
        Status status;
    };
}
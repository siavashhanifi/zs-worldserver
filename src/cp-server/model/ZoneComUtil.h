#pragma once

#include <sys/socket.h>
#include <unistd.h>
#include "marshalling/TCP/Message.h"
#include "data/Zone.h"

namespace zs_worldserver {
    class ZoneComUtil{
    public:
        static void addClientReq(PlayerState, int zoneSocket);
    private:
        ZoneComUtil(){};
    };
}
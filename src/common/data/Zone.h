#pragma once
#include<string>
#include "Border.h"

namespace zs_worldserver{
    struct Zone {
        int id;
        std::string ip;
        int udpPort;
        Border border;
    };
}
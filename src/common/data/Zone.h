#pragma once
#include<string>
#include "Border.h"

namespace zs_worldserver{
    struct Zone {
        std::string ip;
        int udpPort;
        int id;
        Border border;
    };
}
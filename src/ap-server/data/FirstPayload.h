#pragma once

#include "Zone.h"

namespace zs_worldserver{
    
    struct FirstPayload{
        int clientId;
        Zone startZone;
    };
}
#pragma once

#include "marshalling/Message.h"
#include "data/PlayerState.h"
#include "data/Zone.h"

namespace zs_worldserver {
    struct AddClientDTO {
        Status status;
        Zone zone;
        int playerId;
    };
}
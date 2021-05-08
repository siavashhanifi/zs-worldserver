#pragma once

namespace zs_worldserver {
    const size_t UDP_MSG_MAX_BYTES = 1;
    
    enum class StartEndFlag : char {
        START_FLAG = 'A',
        END_FLAG = 'Z',
    };
    
    enum class Action : char {
        INIT_ACTION = '0',
        MOVE_UP = '1',
        MOVE_DOWN = '2',
        MOVE_LEFT = '3',
        MOVE_RIGHT = '4'
    };
}
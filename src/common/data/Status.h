#pragma once

namespace zs_worldserver {
    
    enum class Code{
        OK = 1, 
        FAILED = 0
    };
    
    struct Status{
        Code code;
    };
    
  
    
}
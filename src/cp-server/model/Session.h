#pragma once

#include <mutex>
#include <unordered_map>

namespace zs_worldserver {
    class Session {
    public:
        static Session *singleton;
        static Session *getInstance();
        int generateId();
    private:
        Session();
        int idCounter;
        std::mutex lock;
        //std::unordered_map<int, int> clientSocket;//key:clientid <-> val:clientSocket
    };
}
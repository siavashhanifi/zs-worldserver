#pragma once

#include <mutex>
#include <unordered_map>

namespace zs_worldserver {
    class Session {
    public:
        static Session *singleton;
        static Session *getInstance();
        int generateId();
        bool isClientAddedToZS(int clientId);
        void registerClientAddedToZS(int clientId, int zsSocket);
    private:
        Session();
        int idCounter;
        std::unordered_map<int, int> clientInZone; //key:clientId val: in zsSocket
        std::mutex lock;
    };
}
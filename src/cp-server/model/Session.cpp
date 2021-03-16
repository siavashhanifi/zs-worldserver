#include "Session.h"

zs_worldserver::Session* zs_worldserver::Session::singleton = NULL;
zs_worldserver::Session* zs_worldserver::Session::getInstance(){
    if(singleton == NULL)
        singleton  = new Session();
    return singleton;
}

zs_worldserver::Session::Session(){
    idCounter = 1337;
}

int zs_worldserver::Session::generateId(){
    const std::lock_guard<std::mutex> lockGuard(lock);
    int old = idCounter;
    idCounter++;
    return old;
}
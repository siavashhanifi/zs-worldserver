#include "ZoneComUtil.h"
#include <iostream>

zs_worldserver::Status zs_worldserver::ZoneComUtil::addClientReq(PlayerState ps, int zoneSocket) {
    Message msg(Head::CPZ_ADDCLIENT_REQ, ps);
    send(zoneSocket, msg.bytes, MSG_MAX_BYTES, 0);
    char inBytes[MSG_MAX_BYTES];

    std::cout<<"Start waiting for resp\n";
    //TODO: fix deadlock issue
    recv(zoneSocket, inBytes, MSG_MAX_BYTES, MSG_WAITALL);
    std::cout<<"Recieved mssg\n";

    Message reply(inBytes);
    Status status = reply.getStatus();
    return status;
}
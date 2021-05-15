#include "ZoneComUtil.h"
#include <iostream>

zs_worldserver::Status zs_worldserver::ZoneComUtil::addClientReq(PlayerState ps,
        int zoneSocket) {

    Message msg(Head::CPZ_ADDCLIENT_REQ, ps);
    send(zoneSocket, msg.bytes, MSG_MAX_BYTES, 0);

    //must be allocated dynamically
    //or we will not have enough memory
    //when multiple connection-threads call on this operation
    char *inBytes = new char[MSG_MAX_BYTES];

    recv(zoneSocket, inBytes, MSG_MAX_BYTES, MSG_WAITALL);

    Message reply(inBytes);
    Status status = reply.getStatus();
    delete inBytes;
    return status;
}
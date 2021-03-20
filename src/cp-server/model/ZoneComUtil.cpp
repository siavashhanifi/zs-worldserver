#include "ZoneComUtil.h"

zs_worldserver::Status zs_worldserver::ZoneComUtil::addClientReq(PlayerState ps,                                                                int zoneSocket){
    Message msg(Head::CPZ_ADDCLIENT_REQ, ps);
    send(zoneSocket, msg.bytes, MSG_MAX_BYTES, 0);
    char inBytes[MSG_MAX_BYTES];
    
    int n = 0;
    while(n < MSG_MAX_BYTES){
        n += read(zoneSocket, inBytes, MSG_MAX_BYTES);
    }
    
    Message reply(inBytes);
    Status status = reply.getStatus();
    return status;
}
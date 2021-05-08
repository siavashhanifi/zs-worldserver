#include "Message.h"

void zs_worldserver::Message::serializeHead(){
    bytes[0] = (char)head;
}

void zs_worldserver::Message::serializeStatus(){
    bytes[1] = (char)status;
    bytes[2] = '\0';
}

void zs_worldserver::Message::serializeZone(){    
    std::string zoneString("");
    using std::to_string;
    zoneString += to_string(zone.id) + ':';
    zoneString += zone.ip + ':';
    zoneString += to_string(zone.udpPort)+':';
    zoneString += to_string(zone.border.xMax) + ':';
    zoneString += to_string(zone.border.xMin) + ':';
    zoneString += to_string(zone.border.yMax) + ':';
    zoneString += to_string(zone.border.yMin) + ':';   
    zoneString += to_string(zone.border.zMax) + ':';
    zoneString += to_string(zone.border.zMin) + ':';

    //[head,<bytes>-->zone]
    std::memcpy((bytes + sizeof(head)), zoneString.c_str(),
            zoneString.length() + 1);
}

void zs_worldserver::Message::serializeName() {
    char* cstr = bytes + sizeof(head);
    std::memcpy(cstr, playerName.c_str(), playerName.length() + 1);
}

void zs_worldserver::Message::serializePlayerState() {
    std::string playerStateStr("");
    using std::to_string;
    playerStateStr += to_string(playerState.id) + ':';
    playerStateStr += to_string(playerState.pos.x) + ':';
    playerStateStr += to_string(playerState.pos.y) + ':';
    //[head,<bytes>-->zone]
    std::memcpy((bytes + sizeof(head)), playerStateStr.c_str(),
            playerStateStr.length() + 1);
}

void zs_worldserver::Message::serializePlayerId() {
    std::string playerIdStr("");
    using std::to_string;
    playerIdStr += to_string(playerId) + ':';
    std::memcpy((bytes + sizeof(head)), playerIdStr.c_str(),
            playerIdStr.length() + 1);
}
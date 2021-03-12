#include "Message.h"

void zs_worldserver::Message::serializeHead(){
    bytes[0] = (char)head;
}

void zs_worldserver::Message::dserializeHead(){
    head = (Head)bytes[0];
}

void zs_worldserver::Message::serializeStatus(){
    bytes[1] = (char)status;
    bytes[2] = '\0';
    //std::memcpy(bytes + sizeof(head), &status, sizeof(status));
}

void zs_worldserver::Message::dserializeStatus(){
    //std::memcpy(&status, bytes + sizeof(head), sizeof(status));
    status = (Status)bytes[1];
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
    std::memcpy((bytes + sizeof(head)), zoneString.c_str(), zoneString.length() + 1);
}

void zs_worldserver::Message::dserializeZone(){
    std::string serialized((char*)(bytes + sizeof(head)));
    std::vector<std::string> result;
    std::stringstream ss (serialized);
    std::string item;
    char delim = ':';

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    
    zone.id = stoi(result.at(0));
    zone.ip = result.at(1);
    zone.udpPort = stoi(result.at(2));
    zone.border.xMax = stoi(result.at(3));
    zone.border.xMin = stoi(result.at(4));
    zone.border.yMax = stoi(result.at(5));
    zone.border.yMin = stoi(result.at(6));
    zone.border.zMax = stoi(result.at(7));
    zone.border.zMin = stoi(result.at(8));
}

void zs_worldserver::Message::serializeName() {
    char* cstr = bytes + sizeof(head);
    std::memcpy(cstr, playerName.c_str(), playerName.length() + 1);
}

void zs_worldserver::Message::dserializeName() {
    playerName = std::string((char*)(bytes + sizeof(head)));
}

void zs_worldserver::Message::serializePlayerState() {
    std::string playerStateStr("");
    using std::to_string;
    playerStateStr += to_string(playerState.id) + ':';
    playerStateStr += to_string(playerState.pos.x) + ':';
    playerStateStr += to_string(playerState.pos.y) + ':';

    //[head,<bytes>-->zone]
    std::memcpy((bytes + sizeof(head)), playerStateStr.c_str(), playerStateStr.length() + 1);
}

void zs_worldserver::Message::dserializePlayerState() {
    std::string serialized((char*)(bytes + sizeof(head)));
    std::vector<std::string> result;
    std::stringstream ss(serialized);
    std::string item;
    char delim = ':';

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    playerState.id = stoi(result.at(0));
    playerState.pos.x = stof(result.at(1));
    playerState.pos.y = stof(result.at(2));
}
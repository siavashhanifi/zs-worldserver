#include "Message.h"

void zs_worldserver::Message::dserializeHead(){
    head = (Head)bytes[0];
}

void zs_worldserver::Message::dserializeStatus(){
    //std::memcpy(&status, bytes + sizeof(head), sizeof(status));
    status = (Status)bytes[1];
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

void zs_worldserver::Message::dserializeName() {
    playerName = std::string((char*)(bytes + sizeof(head)));
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

void zs_worldserver::Message::dserializePlayerId() {
    std::string serialized((char*)(bytes + sizeof(head)));
    std::vector<std::string> result;
    std::stringstream ss(serialized);
    std::string item;
    char delim = ':';

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    playerId = stoi(result.at(0));
}
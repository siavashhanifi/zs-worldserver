#include "Message.h"

zs_worldserver::Message::Message(char* bytes){
    this->bytes = new char[strlen(bytes) + 1];
    memcpy(this->bytes, bytes, strlen(bytes)+1);
    
    dserializeHead();
    switch(head){
        case Head::ZCP_ADDZONE_REQ:
        {
            dserializeZone();
            break;
        }
        case Head::CPZ_ADDZONE_RES:
        {
            dserializeStatus();
            break;
        }
        case Head::CCP_ADDCLIENT_REQ:
        {
            dserializeName();
            break;
        }
        case Head::CPZ_ADDCLIENT_REQ:
        {
            dserializePlayerState();
            break;
        }
        default:
            break;
    }
    
}

zs_worldserver::Message::Message(Head head, Zone zone){
    this->head = head;
    this->zone = zone;
    this->bytes = new char[sizeof(head) + 128];
    serializeHead();
    serializeZone();
    size = strlen(bytes) + 1; 
}

zs_worldserver::Message::Message(Head head, Status status){
    this->head = head;
    this->status = status;
    this->bytes = new char[sizeof(head) + sizeof(status) + 1];// + 1('\0')
    serializeHead();
    serializeStatus();//STATUS
    size = strlen(bytes) + 1; 
}

zs_worldserver::Message::Message(Head head, std::string playerName) {
    if (playerName.length() > MAX_NAME_LEN)
        throw std::runtime_error("playerName too long");

    this->head = head;
    this->playerName = playerName;
    this->bytes = new char[sizeof(head) + playerName.length() + 1];
    serializeHead();
    serializeName();
    size = strlen(bytes) + 1;
}

zs_worldserver::Message::Message(Head head, PlayerState playerState) {
    this->head = head;
    this->playerState = playerState;
    this->bytes = new char[sizeof(head) + 128];
    serializeHead();
    serializePlayerState();
    size = strlen(bytes) + 1;
}

zs_worldserver::Head zs_worldserver::Message::getHead() {
    return head;
}

zs_worldserver::Status zs_worldserver::Message::getStatus() {
    return status;
}

zs_worldserver::Zone zs_worldserver::Message::getZone(){
    return zone;
}

std::string zs_worldserver::Message::getPlayerName() {
    return playerName;
}

zs_worldserver::PlayerState zs_worldserver::Message::getPlayerState() {
    return playerState;
}

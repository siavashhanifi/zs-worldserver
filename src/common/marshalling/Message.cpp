#include <string>
#include <memory>
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
        default:
            break;
    }
    
}

zs_worldserver::Message::Message(Head head, Zone zone){
    this->head = head;
    this->zone = zone;
    this->bytes = new char[sizeof(head) + sizeof(zone)];
    serializeHead();
    serializeZone();
}

zs_worldserver::Message::Message(Head head, Status status){
    this->head = head;
    this->status = status;
    this->bytes = new char[sizeof(head) + sizeof(status)];
    serializeHead();
    serializeStatus();//STATUS
}

zs_worldserver::Zone zs_worldserver::Message::getZone(){
    return zone;
}

zs_worldserver::Head zs_worldserver::Message::getHead(){
    return head;
}
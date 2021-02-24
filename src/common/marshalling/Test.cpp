#include "Message.h"
#include <iostream>
using namespace zs_worldserver;
int main(){
    Border border;
    border.xMax = 1;
    border.xMin = 0;
    border.yMax = 1;
    border.yMin = 0;
    border.zMax = 1;
    border.zMin = 0;
   
    Zone zone1;
    zone1.id = 1337;
    zone1.ip = "localhost";
    zone1.udpPort = 27015;
    zone1.border = border;
    
    Message serialize(Head::ZCP_ADDZONE_REQ, zone1);
    char *bytes = serialize.bytes;
    Message deserialize(bytes);
    
    Zone zone2 = deserialize.getZone();
    std::cout<< zone1.id << " " <<zone2.id << "\n";
    std::cout<< zone1.ip << " " <<zone2.ip << "\n";
    std::cout<< zone1.border.xMax << " " <<zone2.border.xMax<< "\n";
    std::cout<< zone1.border.xMin << " " <<zone2.border.xMin<< "\n";
    std::cout<< zone1.border.yMax << " " <<zone2.border.yMax<< "\n";
    std::cout<< zone1.border.yMin << " " <<zone2.border.yMin<< "\n";
    std::cout<< zone1.border.zMax << " " <<zone2.border.zMax<< "\n";
    std::cout<< zone1.border.zMin << " " <<zone2.border.zMin<< "\n";
    
    Status status1 = Status::OK;
    Message serializeStatus(Head::ZCP_ADDZONE_RES, status1);
    bytes = serializeStatus.bytes;
    Message deserializeStatus(bytes);
    Status status2 = deserializeStatus.getStatus();
    std::cout<< (char)status1 << " " <<(char)status2 <<"\n";
}
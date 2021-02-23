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
   
    Zone zone;
    zone.id = 1337;
    zone.ip = "localhost";
    zone.udpPort = 27015;
    zone.border = border;
    
    Message rootMsg(Head::ZCP_ADDZONE_REQ, zone);
    char *bytes = rootMsg.bytes;
    Message msg(bytes);
    Zone zone2 = msg.getZone();
    std::cout<<zone2.id << "\n";
    std::cout<<zone2.ip << "\n";
    std::cout<<zone2.border.xMax<< "\n";
    std::cout<<zone2.border.xMin<< "\n";
    std::cout<<zone2.border.yMax<< "\n";
    std::cout<<zone2.border.yMin<< "\n";
    std::cout<<zone2.border.zMax<< "\n";
    std::cout<<zone2.border.zMin<< "\n";
}
#include "main.h"

using namespace zs_worldserver;

int main(int argc, char **argv){
    std::string cpsIp = argv[1];
    int cpsPort = std::stoi(argv[2]);
    Zone zone;
    zone.id = std::stoi(argv[3]);
    zone.ip = argv[4];
    zone.udpPort = std::stoi(argv[5]);
    Border border;
    border.xMax = std::stoi(argv[6]);
    border.xMin = std::stoi(argv[7]);
    border.yMax = std::stoi(argv[8]);
    border.yMin = std::stoi(argv[9]);
    border.zMax = std::stoi(argv[10]);
    border.zMin = std::stoi(argv[11]);
    zone.border = border;
    
    std::cout << zone.id << std::endl;
    std::cout << zone.ip << std::endl;
    std::cout << zone.udpPort << std::endl;
    std::cout << zone.border.xMax << std::endl;
    std::cout << zone.border.xMin << std::endl;
    std::cout << zone.border.yMax << std::endl;
    std::cout << zone.border.yMin << std::endl;
    std::cout << zone.border.zMax << std::endl;
    std::cout << zone.border.zMin << std::endl;


    Controller* controller =  controller->getInstance();
    controller->init(zone, cpsIp, cpsPort);
    return 0;   
}
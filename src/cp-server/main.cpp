#include"main.h"
#include "network/TCPListener.h"

using namespace zs_worldserver;
        
int main(int argc, char** argv) {
    std::cout << "zs_worldserver - Client Placement Server\n";
    std::cout << "Siavash Hanifi\n" << "listening to port: "
            << std::stoi(argv[1]) << std::endl;
    Zones *zones = zones->getInstance();
    TCPListener tcpL(std::stoi(argv[1]));
    
    return 0;
}


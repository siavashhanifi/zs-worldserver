#include"main.h"

using namespace zs_worldserver;

void *startTCPListener(void *args){
    int port = *((int*)args);
    TCPListener *tcpList = new TCPListener(port);
    delete tcpList;
    return 0;
}

void *startUDPListener(void *args){
    int port = *((int*)args);
    UDPListener *udpList = new UDPListener(port);
    delete udpList;
    return 0;
}

int main(int argc, char *argv[]){
    std::cout << "Zone Segmented World Server v1 - Siavash Hanifi\n";
    std::cout << "starting..\n";
    int tcpListPort = 27015;
    int udpListPort = 27016;
    try{
    using thread = std::thread;
    thread tcpListener = thread(&startTCPListener, (void*)&tcpListPort);
    tcpListener.detach();
    thread udpListener = thread(&startUDPListener, (void*)&udpListPort);
    udpListener.detach();
    while(true){
        char c;
        std::cin>>c;
    }
    return 0;
    } catch(const std::runtime_error& error){
        std::cerr << error.what() << std::endl;
        return -1;
    }
    
}
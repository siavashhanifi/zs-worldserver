#include "CmdIO.h"

zs_worldserver::CmdIO::CmdIO() {
    controller = controller->getInstance();
    queryCPS();
    queryName();
    controller->joinGame(cpsAddress, name);
}

void zs_worldserver::CmdIO::queryCPS() {
	std::string ipPort;
	std::cout << "Enter (CPS)ip:port: ";
	std::cin >> ipPort;

    std::vector<std::string> result;
    std::stringstream ss(ipPort);
    std::string item;
    char delim = ':';

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    cpsAddress.ip = result.at(0);
    cpsAddress.port = std::stoi(result.at(1));
}

void zs_worldserver::CmdIO::queryName() {
    do {
        std::cout << "Enter name(max 8 chars): ";
        std::cin >> name;
        if (name.length() > 8)
            std::cout << "Error: name too long.\n";
    } while (name.length() > 8);
}
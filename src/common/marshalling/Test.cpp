#include "Message.h"
#include <string>
#include <iostream>
using namespace zs_worldserver;

void test_ZCP_ADDZONE_REQ();
void test_CCP_ADDCLIENT_REQ();
void test_CPZ_ADDCLIENT_REQ();

int main(){
    test_CPZ_ADDCLIENT_REQ();
    return 0;
}

void test_CPZ_ADDCLIENT_REQ() {
    Position pos = { 2, 3 };
    PlayerState ps = { 1337, pos };
    Message serialize(Head::CPZ_ADDCLIENT_REQ, ps);
    PlayerState ps2 = serialize.getPlayerState();
    std::cout << "ID: " << ps2.id << "\n";
    std::cout << "x: " << ps2.pos.x << "\n";
    std::cout << "y: " << ps2.pos.y << "\n";
    Message deserialize(serialize.bytes);
    PlayerState ps3 = deserialize.getPlayerState();
    std::cout << "ID: " << ps3.id << "\n";
    std::cout << "x: " << ps3.pos.x << "\n";
    std::cout << "y: " << ps3.pos.y << "\n";
}

void test_CCP_ADDCLIENT_REQ() {
    std::string name = "Siavash";
    Message serialize(Head::CCP_ADDCLIENT_REQ, name);
    char* bytes = serialize.bytes;
    std::cout << serialize.getPlayerName() << "\n";
    Message deserialize(bytes);
    std::cout << deserialize.getPlayerName() << "\n";
}

void test_ZCP_ADDZONE_REQ() {
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
    char* bytes = serialize.bytes;
    Message deserialize(bytes);

    Zone zone2 = deserialize.getZone();
    std::cout << zone1.id << " " << zone2.id << "\n";
    std::cout << zone1.ip << " " << zone2.ip << "\n";
    std::cout << zone1.border.xMax << " " << zone2.border.xMax << "\n";
    std::cout << zone1.border.xMin << " " << zone2.border.xMin << "\n";
    std::cout << zone1.border.yMax << " " << zone2.border.yMax << "\n";
    std::cout << zone1.border.yMin << " " << zone2.border.yMin << "\n";
    std::cout << zone1.border.zMax << " " << zone2.border.zMax << "\n";
    std::cout << zone1.border.zMin << " " << zone2.border.zMin << "\n";

    Status status1 = Status::OK;
    Message serializeStatus(Head::CPZ_ADDZONE_RES, status1);
    bytes = serializeStatus.bytes;
    Message deserializeStatus(bytes);
    Status status2 = deserializeStatus.getStatus();
    std::cout << (char)status1 << " " << (char)status2 << "\n";
}
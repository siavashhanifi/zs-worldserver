#include "ZSCom.h"

zs_worldserver::ZSCom* zs_worldserver::ZSCom::singleton = nullptr;
zs_worldserver::ZSCom* zs_worldserver::ZSCom::getInstance() {
	if (singleton == nullptr)
		singleton = new ZSCom();
	return singleton;
}

zs_worldserver::ZSCom::ZSCom() {
	//required before using sockets on windows.
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		std::cerr << "Error at WSAStartup();" << WSAGetLastError() << std::endl;

	connection = INVALID_SOCKET;
	zsAddress = { 0 };
	game = game->getInstance();
}

void zs_worldserver::ZSCom::init(Zone zone) {
	this->zsAddress.sin_family = AF_INET;
	this->zsAddress.sin_addr.s_addr = inet_addr(zone.ip.c_str());
	this->zsAddress.sin_port = htons(zone.udpPort);
	createSocket(zone);
}

void zs_worldserver::ZSCom::createSocket(Zone zone) {
	connection = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

void zs_worldserver::ZSCom::readInMsg() {
	size_t zsAddrSize = sizeof(zsAddress);
	int rc = recvfrom(connection, inAndOutBytes, 
						UDP_MSG_MAX_BYTES,
						0, 
						(sockaddr*)&zsAddress,
						(socklen_t*)&zsAddrSize);
}

void zs_worldserver::ZSCom::listenForNextInMsg() {
	while (connection != INVALID_SOCKET) {
		readInMsg();
		handleInMsg();
	}
}

void zs_worldserver::ZSCom::handleInMsg() {
	switch (inAndOutBytes[0]) {
		case (char)Action::MOVE_UP: {
			std::cout << "got move up";
			game->playerState.pos.y += 0.01f;
			break;
		}
		default: {
			break;
		}
	}
}

void zs_worldserver::ZSCom::sendMsg() {
	sendto(connection, inAndOutBytes, UDP_MSG_MAX_BYTES, 0, (sockaddr*)&zsAddress, sizeof(zsAddress));
}

void zs_worldserver::ZSCom::sendInitReq() {
	for (int i = 0; i < 10; i++) {
		inAndOutBytes[0] = (char)Action::INIT_ACTION;
		sendMsg();
		readInMsg();
		handleInMsg();
	}
}
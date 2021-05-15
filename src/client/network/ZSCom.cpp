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

void zs_worldserver::ZSCom::connectToZS(Zone zone) {
	createSocket(zone);
	connectSocket();
}

void zs_worldserver::ZSCom::createSocket(Zone zone) {
	this->zsAddress.sin_family = AF_INET;
	this->zsAddress.sin_addr.s_addr = inet_addr(zone.ip.c_str());
	this->zsAddress.sin_port = htons(zone.udpPort);
	connection = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

void zs_worldserver::ZSCom::connectSocket() {
	int rc;
	rc = connect(connection, (SOCKADDR*)&zsAddress, sizeof(zsAddress));
	if (rc == SOCKET_ERROR) {
		closesocket(connection);
		connection = INVALID_SOCKET;
		std::cerr << "Failed to connect: " << WSAGetLastError() << std::endl;
	}
}

void zs_worldserver::ZSCom::readInMsg() {
	size_t zsAddrSize = sizeof(zsAddress);
	recvfrom(connection, inAndOutBytes, UDP_MSG_MAX_BYTES, MSG_WAITALL, (sockaddr*)&zsAddress, (int*)&zsAddrSize);
}

void zs_worldserver::ZSCom::listenForNextInMsg() {
	while (connection != INVALID_SOCKET) {
		readInMsg();
		handleInMsg();
	}
}

void zs_worldserver::ZSCom::handleInMsg() {
	switch (inAndOutBytes[0]) {
	case ' ': {

	}
	default:
		break;
	}
}
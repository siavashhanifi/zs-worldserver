#include "CPSCom.h"

zs_worldserver::CPSCom* zs_worldserver::CPSCom::singleton = nullptr;
zs_worldserver::CPSCom* zs_worldserver::CPSCom::getInstance() {
	if (singleton == nullptr)
		singleton = new CPSCom();
	return singleton;
}

zs_worldserver::CPSCom::CPSCom() {
	connection = INVALID_SOCKET;
	cpsAddress = { 0 };
	msgIn = nullptr;
	toSend = nullptr;
	game = game->getInstance();
}

void zs_worldserver::CPSCom::connectToCPS(CPSAddress cpsAddress) {
	createSocket(cpsAddress);
	connectSocket();
}

void zs_worldserver::CPSCom::createSocket(CPSAddress cpsAddress) {
	WSADATA wsaData;
	//required before using sockets on windows.
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		std::cerr << "Error at WSAStartup();" << WSAGetLastError() << std::endl;

	//set socket details ie. specify protocols, ip-addresses and port to use.

	std::cout << "ip: " << cpsAddress.ip << "\n";
	std::cout << "port: " << cpsAddress.port << std::endl;

	this->cpsAddress.sin_family = AF_INET;
	//binds socket to listen at any interface (all interfaces?).
	this->cpsAddress.sin_addr.s_addr = inet_addr(cpsAddress.ip.c_str());
	this->cpsAddress.sin_port = htons(cpsAddress.port);

	connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

}

void zs_worldserver::CPSCom::connectSocket() {
	int rc;
	rc = connect(connection, (SOCKADDR*)&cpsAddress, sizeof(cpsAddress));
	if (rc == SOCKET_ERROR) {
		closesocket(connection);
		connection = INVALID_SOCKET;
		std::cerr << "Failed to connect: " << WSAGetLastError() << std::endl;
	}
}

zs_worldserver::Status zs_worldserver::CPSCom::addClient(std::string name) {
	toSend = new Message(Head::CCP_ADDCLIENT_REQ, name);
	send(connection, toSend->bytes, MSG_MAX_BYTES, 0);
	delete toSend;

	readReply();
	Status status = msgIn->getStatus();
	delete msgIn;

	return status;
}

void zs_worldserver::CPSCom::readReply() {
	char* inBytes = new char[MSG_MAX_BYTES];

	int n = 0;
	while (n < MSG_MAX_BYTES) {
		n += recv(connection, inBytes, MSG_MAX_BYTES, 0);
	}

	msgIn = new Message(inBytes);
	delete[] inBytes;
}

void zs_worldserver::CPSCom::readNext() {
	while (connection != INVALID_SOCKET) {
		char* inBytes = new char[MSG_MAX_BYTES];

		int n = 0;
		while (n < MSG_MAX_BYTES) {
			n += recv(connection, inBytes, MSG_MAX_BYTES, 0);
		}

		msgIn = new Message(inBytes);
		delete[] inBytes;
		handleInMsg();
	}
}

void zs_worldserver::CPSCom::handleInMsg() {
	Head head = msgIn->getHead();
	switch (head) {
	case Head::CPC_ADDCLIENT_RES:
	{
		Status status = msgIn->getStatus();
		if (status == Status::OK) {
			PlayerState ps = msgIn->getPlayerState();
			game->playerState = ps;
		}
		break;
	}
	default:
		break;
	}
}
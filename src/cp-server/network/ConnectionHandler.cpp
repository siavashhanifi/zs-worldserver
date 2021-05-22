#include "ConnectionHandler.h"
#include <iostream>

zs_worldserver::ConnectionHandler::ConnectionHandler(int tcpConnection) {
    this->connection = tcpConnection;
    controller = controller->getInstance();
    listenForInMsgs();
}

zs_worldserver::ConnectionHandler::~ConnectionHandler() {
    close(connection);
}

void zs_worldserver::ConnectionHandler::listenForInMsgs() {
    while (true) {
        recv(connection, bytes, MSG_MAX_BYTES, MSG_WAITALL);
        inMsg = new Message(bytes);
        handleMessage();
        delete inMsg;
    }
}

void zs_worldserver::ConnectionHandler::handleMessage() {
    Head head = inMsg->getHead();
    switch (head) {
        case Head::ZCP_ADDZONE_REQ:
        {
            Zone zone = inMsg->getZone();
            controller->addZone(zone, connection);
            reply = new Message(Head::CPZ_ADDZONE_RES, Status::OK);
            sendReply();
            delete reply;
            break;
        }
        case Head::CCP_ADDCLIENT_REQ:
        {
            std::string name = inMsg->getPlayerName();
            AddClientDTO dto = controller->addClient(name);

            //Send responses
            reply = new Message(Head::CPC_ADDCLIENT_RES_ONE, dto.status);
            sendReply();
            delete reply;

            reply = new Message(Head::CPC_ADDCLIENT_RES_TWO, dto.zone);
            sendReply();
            delete reply;


            reply = new Message(Head::CPC_ADDCLIENT_RES_THREE, dto.playerId);
            sendReply();
            delete reply;

            break;
        }
        case Head::ZCP_ADDCLIENT_RES:
        {
            int clientId = inMsg->getPlayerId();
            controller->registerClientAdded(clientId, connection);
        }
        default:
            break;
    }
}

void zs_worldserver::ConnectionHandler::sendReply() {
    char *bytes = reply->bytes;
    send(connection, bytes, MSG_MAX_BYTES, 0);
}
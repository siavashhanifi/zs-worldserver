cmake_minimum_required (VERSION 3.8)

project("ap-server")

add_executable (${PROJECT_NAME} "main.cpp"
 "main.h"
 "clientHandling/TCPListener.cpp"
 "clientHandling/TCPListener.h"
 "clientHandling/ClientTCPHandler.cpp"
 "clientHandling/ClientTCPHandler.h"
 "clientHandling/UDPListener.cpp"
 "clientHandling/UDPListener.h"
 "clientHandling/ClientUDPHandler.cpp"
 "clientHandling/ClientUDPHandler.h"
 "zoneHandling/ZoneHandler.cpp"
 "zoneHandling/ZoneHandler.h"
 "players/ActivePlayers.cpp"
 "players/ActivePlayers.h"
 "netUtility/UDPUtility.cpp"
 "netUtility/UDPUtility.h"
 "netUtility/TCPUtility.cpp"
 "netUtility/TCPUtility.h"
 "data/Zone.h"
 "data/UDPAddress.h"
 "data/FirstPayload.h"
 "data/AddClientPayload.h")

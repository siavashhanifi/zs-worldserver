cmake_minimum_required (VERSION 3.8)

project("cp-server")

add_executable (${PROJECT_NAME} 
    "main.cpp"
    "main.h"
    "controller/Controller.cpp"
    "controller/Controller.h"
    "network/ConnectionHandler.cpp"
    "network/ConnectionHandler.h"
    "network/TCPListener.cpp"
    "network/TCPListener.h"
    "model/Zones.cpp"
    "model/Zones.h"
 )
 
 target_link_libraries(${PROJECT_NAME} common pthread)
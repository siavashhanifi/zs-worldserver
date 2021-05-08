cmake_minimum_required (VERSION 3.8)

add_library(common
    "data/Zone.h"
    "data/Border.h"
    "data/Position.h"
    "data/PlayerState.h"
    "data/CPSAddress.h"
    "data/AddClientDTO.h"
    "marshalling/TCP/Message.h"
    "marshalling/TCP/Message.cpp"
    "marshalling/TCP/Serialization.cpp"
    "marshalling/TCP/Deserialization.cpp"
    "marshalling/UDP/UDPMessageHelper.h"
 )

target_include_directories (common PUBLIC .)

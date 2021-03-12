cmake_minimum_required (VERSION 3.8)

add_library(common
    "data/Zone.h"
    "data/Border.h"
    "data/Position.h"
    "data/PlayerState.h"
    "data/CPSAddress.h"
    "marshalling/Message.h"
    "marshalling/Message.cpp"
    "marshalling/Serialization.cpp"
 )

target_include_directories (common PUBLIC .)

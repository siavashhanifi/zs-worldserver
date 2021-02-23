cmake_minimum_required (VERSION 3.8)

add_library(Common SHARED
    "data/Zone.h"
    "data/Border.h"
    "marshalling/Message.h"
    "marshalling/Message.cpp"
    "marshalling/Serialization.cpp"
 )

target_include_directories (Common PUBLIC .)

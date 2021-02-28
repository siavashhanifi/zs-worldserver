project("zone-server")

add_executable(${PROJECT_NAME}
    "main.cpp"
    "main.h"
    "network/CPSCommunicator.cpp"
    "network/CPSCommunicator.h"
)

target_link_libraries(${PROJECT_NAME} common)
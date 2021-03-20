project("zone-server")

add_executable(${PROJECT_NAME}
    "main.cpp"
    "main.h"
    "network/CPSCommunicator.cpp"
    "network/CPSCommunicator.h"
    "controller/Controller.h"
    "controller/Controller.cpp"
    "model/Game.h"
    "model/Game.cpp"
)

target_link_libraries(${PROJECT_NAME} common pthread)
project("client")

add_executable(${PROJECT_NAME} WIN32
"main.cpp"
"main.h"
"view/WindowCreator.cpp"
"view/WindowCreator.h"
"view/Graphics.cpp"
"view/Graphics.h"
)

target_link_libraries(${PROJECT_NAME} common d2d1)
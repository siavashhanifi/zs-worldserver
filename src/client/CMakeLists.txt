project("client")

add_executable(${PROJECT_NAME}
"main.cpp"
"main.h"
"view/Graphics.h"
"view/Graphics.cpp"
"view/CmdIO.h"
"view/CmdIO.cpp"
"network/CPSCom.h"
"network/CPSCom.cpp"
"network/ZSCom.h"
"network/ZSCom.cpp"
"network/CPSAddress.h"
"controller/Controller.h"
"controller/Controller.cpp"
"model/Game.h"
"model/Game.cpp"
)

target_link_libraries(${PROJECT_NAME} common GLEW::GLEW glfw glm::glm opengl32.lib glu32.lib)
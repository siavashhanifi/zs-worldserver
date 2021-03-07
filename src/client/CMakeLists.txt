project("client")

add_executable(${PROJECT_NAME}
"main.cpp"
"main.h"
)

target_link_libraries(${PROJECT_NAME} common GLEW::GLEW glfw glm::glm opengl32.lib glu32.lib)
#include "Graphics.h"

using namespace glm;

zs_worldserver::Game* zs_worldserver::Graphics::game = game->getInstance();

void zs_worldserver::Graphics::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        game->playerState.pos.y += 0.03f;

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
        game->playerState.pos.x -= 0.03f;

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        game->playerState.pos.y -= 0.03f;

    if (key == GLFW_KEY_D && action == GLFW_PRESS)
        game->playerState.pos.x += 0.03f;

    if (key == GLFW_KEY_W && action == GLFW_REPEAT)
        game->playerState.pos.y += 0.03f;

    if (key == GLFW_KEY_A && action == GLFW_REPEAT)
        game->playerState.pos.x -= 0.03f;

    if (key == GLFW_KEY_S && action == GLFW_REPEAT)
        game->playerState.pos.y -= 0.03f;

    if (key == GLFW_KEY_D && action == GLFW_REPEAT) //remove these ;;;
        game->playerState.pos.x += 0.03f;
}

void zs_worldserver::Graphics::error_callback(int error, const char* description) {
    std::cerr << "Error: " << description << "\n";
}

void zs_worldserver::Graphics::draw() {
    glLineWidth(5.0);
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glBegin(GL_LINES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(1.f, 0.50f);
    glVertex2f(-1.f, 0.50f);
    glVertex2f(1.f, 0.f);
    glVertex2f(-1.f, 0.f);
    glVertex2f(1.f, -0.50f);
    glVertex2f(-1.f, -0.50f);
    glEnd();

    glPointSize(10.0);
    glBegin(GL_POINTS);
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(game->playerState.pos.x, game->playerState.pos.y);
    glEnd();
}

//Initialise GLFW
zs_worldserver::Graphics::Graphics() {

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwSetErrorCallback(error_callback);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
    }

    // Ensure we can capture the escape key being pressed below
    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    while (!glfwWindowShouldClose(window)) {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !
        draw();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
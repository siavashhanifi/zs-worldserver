#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../client/model/Game.h"

namespace zs_worldserver {
	class Graphics {
	public:
		Graphics();
	private:
		static Game* game;
		GLFWwindow* window;
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void error_callback(int error, const char* description);
		void draw();
	};
}
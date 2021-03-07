#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace zs_worldserver {
	class Graphics {
	public:
		Graphics();
	private:
		GLFWwindow* window;
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void error_callback(int error, const char* description);
		void draw();
	};
}
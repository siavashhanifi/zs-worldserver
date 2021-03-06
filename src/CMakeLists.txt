cmake_minimum_required (VERSION 3.8)

project("zs-worldsrv")


# define linux
if(UNIX AND NOT APPLE)
	set(LINUX TRUE)
endif()

# code used across client, 
# zone-server and cp-server
add_subdirectory(common)

# client is targeted for windows
if(WIN32)
	# find OpenGL includes and libs
	find_package(GLEW MODULE)
	find_package(glfw3 CONFIG)
	find_package(glm CONFIG)
	add_subdirectory(client)

endif(WIN32)

# servers are targeted for linux
if(LINUX)
	add_subdirectory(cp-server)
	add_subdirectory(zone-server)
endif(LINUX)
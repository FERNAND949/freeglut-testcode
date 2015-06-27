
cmake_minimum_required(VERSION 2.8)

#set project
PROJECT(freegl)

#find glut
find_package(GLUT REQUIRED glut)
#include_directories($(GLUT_INCLUDE_DIRS))
#link_directories($(GLUT_LIBRARY_DIRS))
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
	message(ERROR "GLUT not found")
endif(NOT GLUT_FOUND)


#find opnegl
find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIRS})
#link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
	    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#コンパイルオプション
#CXXはC++
#-gはデバッグをオン
#-Wallは警告オプション
#set(CMAKE_CXX_FLAGS "-g -Wall")


add_executable(out main.cpp )
#ライブラリのリンク
target_link_libraries(out ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} m)















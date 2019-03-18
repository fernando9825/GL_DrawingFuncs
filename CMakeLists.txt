cmake_minimum_required(VERSION 3.13)
project(GL_DrawingFuncs)

# C++ 17 standard
set(CMAKE_CXX_STANDARD 17)

# adding GLUT lib

find_package(GLUT REQUIRED) #search for GLUT lib
include_directories(${GLUT_INCLUDE_DIRS}) # add directories
link_directories(${GLUT_LIBRARY_DIRS}) # link directories
add_definitions(${GLUT_DEFINITIONS}) #A add definitions


# adding OPENGL lib

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

# adding files
add_library(GL_DrawingFuncs SHARED GL_DrawingFuncs.cpp GL_DrawingFuncs.h) # Agregando nombre del script y compilado


# lib linking

target_link_libraries(GL_DrawingFuncs ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

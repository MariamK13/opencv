cmake_minimum_required(VERSION 3.0)
project(project-opencv-Face_Detection)
# Find OpenCV package on your system
find_package(OpenCV REQUIRED)
# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})
# Add executable for your project
add_executable(my_opencv_app test.cpp)
# Link OpenCV libraries
target_link_libraries(my_opencv_app ${OpenCV_LIBS})

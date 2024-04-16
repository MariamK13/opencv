cmake_minimum_required(VERSION 3.0)
project(new-video-project-opencv)

#Set the path to your Python script
set(PYTHON_SCRIPT "python/test.py")

#Add a custom target to run the Python script

add_custom_target(run_python_script
       COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/python/test.py
       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
       COMMENT "Running Python script"
       )  


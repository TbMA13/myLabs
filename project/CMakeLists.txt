cmake_minimum_required(VERSION 3.15) 
set(PROJECT_NAME MyProject)

project("${PROJECT_NAME}")

include_directories("inc/")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" project.cpp inc/numbersFunc.h numbersFunc.cpp example.cpp inc/example.h inc/logger.h)

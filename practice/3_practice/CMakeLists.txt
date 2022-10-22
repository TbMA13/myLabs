cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME 3_practice)	

project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" 3_pract.cpp)

file(COPY input.txt DESTINATION assets/)
file(COPY output.txt DESTINATION assets/)
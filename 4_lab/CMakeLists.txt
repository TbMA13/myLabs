cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

									 # Если версия установленой программы

									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME 4_lab)				 # имя проекта		 

project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${CMAKE_MODULE_PATH}")

add_definitions(-DSFML_STATIC)

add_executable("${PROJECT_NAME}" 4_lab.cpp Circle.cpp Circle.h)

find_package(SFML REQUIRED)

if(SFML_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
    message(${SFML_INCLUDE_DIRS})
    message(${SFML_LIBRARIES})
endif()

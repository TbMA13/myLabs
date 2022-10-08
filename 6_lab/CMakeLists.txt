cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

									 # Если версия установленой программы

									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME 6_lab)				 # имя проекта		 

project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")

add_executable("${PROJECT_NAME}" 6_lab.cpp
						inc/read_file.hpp
						src/read_file.cpp
						inc/process_file.hpp
						src/process_file.cpp
						inc/output_file.hpp
						src/output_file.cpp
						)

file(COPY text.txt DESTINATION assets/)
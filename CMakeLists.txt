cmake_minimum_required(VERSION 3.16)
project(template-concept)

set(CMAKE_VERBOSE_MAKEFILE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-std=c++20)
add_compile_options(-stdlib=libstdc++)


add_executable(template-concept 
    main.cpp
)

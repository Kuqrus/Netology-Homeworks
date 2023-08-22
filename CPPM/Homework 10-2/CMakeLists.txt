cmake_minimum_required(VERSION 3.22.0)

project(figures_cmake)

set(SOURCE_EXE Homework_6-3.cpp)

set(SOURCE_LIB equilateral_triangle.cpp isosceles_triangle.cpp parallelogram.cpp print_info.cpp quad.cpp rectangle.cpp rhomb.cpp right_triangle.cpp shape.cpp square.cpp triangle.cpp)

add_library(lib STATIC ${SOURCE_LIB})
add_executable(figures ${SOURCE_EXE})

target_link_libraries(figures lib)



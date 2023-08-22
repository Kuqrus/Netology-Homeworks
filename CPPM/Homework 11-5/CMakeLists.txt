cmake_minimum_required (VERSION 3.22.0)
project (dllShapes)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(shapesStart startFile.cpp)

set(CPP_FILES print_info.cpp shape.cpp triangle.cpp right_triangle.cpp isosceles_triangle.cpp equilateral_triangle.cpp quad.cpp rectangle.cpp square.cpp parallelogram.cpp rhomb.cpp)
set(H_FILES print_info.h shape.h triangle.h right_triangle.h isosceles_triangle.h equilateral_triangle.h quad.h rectangle.h square.h parallelogram.h rhomb.h)

add_library(dynamicLib SHARED ${CPP_FILES} ${H_FILES})

target_link_libraries(shapesStart dynamicLib)
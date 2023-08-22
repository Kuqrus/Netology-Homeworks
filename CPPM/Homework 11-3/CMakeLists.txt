cmake_minimum_required (VERSION 3.22.0)
project (dllLeaver)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(dynamicLib SHARED leaver.cpp leaver.h)
add_executable(leaverStart source.cpp)

target_link_libraries(leaverStart dynamicLib)
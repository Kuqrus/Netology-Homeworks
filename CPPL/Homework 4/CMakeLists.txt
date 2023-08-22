cmake_minimum_required (VERSION 3.20.0)

project (Homework_4)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Homework_4 "Homework 4.cpp" "List.h" "List.cpp")

add_subdirectory(Catch2 Catch2-build)
add_executable(Homework_4-tests "Homework 4_test.cpp" "List.h" "List.cpp")
target_link_libraries(Homework_4-tests PRIVATE Catch2::Catch2)
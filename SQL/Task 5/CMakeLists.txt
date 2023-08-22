cmake_minimum_required(VERSION 3.2)
project(MyDB)

set(PostgreSQL_ADDITIONAL_VERSIONS "15")

add_executable(MyDB main.cpp "db_editor.h" "db_editor.cpp")

add_subdirectory (C:\\Users\\kuqrus\\Desktop\\Homework\\libpqxx-7.7.5 libpqxx-build)

target_compile_features(MyDB PRIVATE cxx_std_17)

target_link_libraries(MyDB pqxx)
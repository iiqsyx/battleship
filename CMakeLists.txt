cmake_minimum_required(VERSION 3.20.)
project(battleship)

file(GLOB project
    src/*
)

add_executable(battleship ${project})

add_custom_command(
    TARGET battleship
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}\\SFML\\bin"
        "${CMAKE_CURRENT_BINARY_DIR}/Debug"
)

set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}\\SFML\\lib\\cmake\\SFML")
target_link_libraries(battleship sfml-graphics)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)

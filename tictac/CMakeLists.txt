cmake_minimum_required(VERSION 3.1)

project(tictac)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(tictac main.cpp)
target_link_libraries(tictac sfml-graphics)

configure_file(cross.png cross.png COPYONLY)
configure_file(dot.png dot.png COPYONLY)

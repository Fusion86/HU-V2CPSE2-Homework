cmake_minimum_required(VERSION 3.1)

project(factory)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(factory main.cpp)
target_link_libraries(factory sfml-graphics sfml-audio)

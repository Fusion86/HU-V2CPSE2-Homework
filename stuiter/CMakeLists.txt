cmake_minimum_required(VERSION 3.1)

project(stuiter)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(stuiter main.cpp ball.cpp)
target_link_libraries(stuiter sfml-graphics sfml-audio)

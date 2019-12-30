cmake_minimum_required(VERSION 3.1)

project(stl)

add_executable(stl main.cpp)
configure_file(james.txt james.txt COPYONLY)

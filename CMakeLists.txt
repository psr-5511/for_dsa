cmake_minimum_required(VERSION 3.21)
project(Stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stack Stack_using_arrays.cpp)

add_executable(Stack_using_arrays Stack_using_arrays.cpp)
add_executable(Stack_using_LinkedList Stack_using_LinkedList.cpp)
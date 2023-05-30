cmake_minimum_required(VERSION 3.24)
project(idz2_sem4)

set(CMAKE_CXX_STANDARD 17)

add_executable(idz2_sem4 cpp/main.cpp headers/DynamicArrayInt.h headers/MyCustomException.h cpp/DynamicArrayInt.cpp)

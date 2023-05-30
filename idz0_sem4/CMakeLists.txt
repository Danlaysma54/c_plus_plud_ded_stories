cmake_minimum_required(VERSION 3.0.0)
project(Test VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(idz0_sem4 cpp/main.cpp cpp/Methods.cpp headers/Methods.h headers/Container.h headers/Data.h headers/MyCustomException.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

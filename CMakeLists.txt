cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project("SimpleValidator")
add_executable(validator main.cpp)
add_executable(checker checker.cpp)


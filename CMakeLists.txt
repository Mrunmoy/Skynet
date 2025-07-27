cmake_minimum_required(VERSION 3.10)
project(skynet CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(skynet main.cpp skynet.cpp)

enable_testing()
add_subdirectory(tests)

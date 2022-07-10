cmake_minimum_required(VERSION 3.10)
project(INFO-F202_projet_cpp)


set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


add_subdirectory(src)
add_executable(INFO-F202_projet_cpp Main.cpp)
TARGET_LINK_LIBRARIES(INFO-F202_projet_cpp PRIVATE core)


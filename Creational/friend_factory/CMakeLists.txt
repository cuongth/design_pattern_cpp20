cmake_minimum_required(VERSION 3.30)
project(friend_factory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(friend_factory main.cpp
        Point.h)

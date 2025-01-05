cmake_minimum_required(VERSION 3.30)
project(person)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(person main.cpp
        Person.cpp
        Person.h
        PersonBuilder.cpp
        PersonBuilder.h
        PersonJobBuilder.h
        PersonAddressBuilder.h)

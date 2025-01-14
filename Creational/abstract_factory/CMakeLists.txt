cmake_minimum_required(VERSION 3.30)
project(abstract_factory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(abstract_factory main.cpp
        HotDrink.h
        HotDrinkFactory.h
        TeaFactory.h
        CoffeeFactory.h
        DrinkFactory.h)

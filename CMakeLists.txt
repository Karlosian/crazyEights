cmake_minimum_required(VERSION 3.30)
project(crazyEights)

set(CMAKE_CXX_STANDARD 20)

add_executable(crazyEights main.cpp
        cmake-build-debug/Card.cpp
        cmake-build-debug/Card.h
        cmake-build-debug/Suit.h
        cmake-build-debug/Deck.cpp
        cmake-build-debug/Deck.h
        cmake-build-debug/Face.h
)

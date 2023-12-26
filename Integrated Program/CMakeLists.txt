cmake_minimum_required(VERSION 3.27)
project(Integrated_program)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Integrated_program
        BoardGame_Classes.hpp
        GameManager.cpp
        Integrated_Game.cpp
        Player.cpp
        RandomPlayer.cpp
        X_O_Board.cpp)

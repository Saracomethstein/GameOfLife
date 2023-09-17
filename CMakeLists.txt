cmake_minimum_required(VERSION 3.26)
project(Game_of_life C)

set(CMAKE_C_STANDARD 11)

include_directories(MacOS/headers)

add_executable(Game_of_life
        MacOS/headers/gameOfLife.h
        MacOS/display.c
        MacOS/displayMenu.c
        MacOS/gameOfLife.c
        MacOS/initialize.c
        MacOS/memory_management.c
        MacOS/update_grid.c
        Windows/game_of_life.c)

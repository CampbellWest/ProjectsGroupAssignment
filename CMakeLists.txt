cmake_minimum_required(VERSION 3.26)
project(Group_Assignment C)

set(CMAKE_C_STANDARD 99)

add_executable(Group_Assignment main.c
        List.c
        List.h
        Item.c
        Item.h
        Functionality.c
        Functionality.h
)

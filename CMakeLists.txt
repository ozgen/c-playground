cmake_minimum_required(VERSION 3.30)
project(c_playground C)

set(CMAKE_C_STANDARD 11)

add_executable(c_playground main.c
        other.h
        other.c
        linkedlist.h
        linkedlist.c
        insert.h
        insert.c)

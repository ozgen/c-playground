cmake_minimum_required(VERSION 3.28)
project(c_playground C)

set(CMAKE_C_STANDARD 11)

add_executable(c_playground main.c
        other.h
        other.c
        linkedlist.h
        linkedlist.c
        insert.h
        insert.c)
# Link against the math library
target_link_libraries(c_playground m)
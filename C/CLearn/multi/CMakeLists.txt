cmake_minimum_required(VERSION 3.10)


# set the project name
project(multi)

add_executable(threads
    ./threads.c
)

TARGET_LINK_LIBRARIES( threads
pthread
)
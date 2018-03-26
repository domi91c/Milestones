cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Milestone_1.cpp Task.cpp Task.h Utilities.cpp Utilities.h)
add_executable(untitled ${SOURCE_FILES} clean_file.dat)
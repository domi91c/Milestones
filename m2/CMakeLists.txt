cmake_minimum_required(VERSION 3.8)
project(m2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Milestone_2.cpp
        Task.cpp Task.h
        Utilities.cpp Utilities.h
        Item.cpp Item.h
        CustomerItem.cpp CustomerItem.h
        CustomerOrder.cpp CustomerOrder.h
        )

add_executable(untitled ${SOURCE_FILES} CustomerOrders_Malformed.dat ItemList_Malformed.dat)
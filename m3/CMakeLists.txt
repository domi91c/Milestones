cmake_minimum_required(VERSION 3.8)
project(m3)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        Milestone_3.cpp
        Task.cpp Task.h
        Utilities.cpp Utilities.h
        Item.cpp Item.h
        CustomerItem.cpp CustomerItem.h
        CustomerOrder.cpp CustomerOrder.h
        TaskManager.cpp TaskManager.h OrderManager.cpp OrderManager.h ItemManager.cpp ItemManager.h)

add_executable(untitled ${SOURCE_FILES} CustomerOrders_Malformed.dat ItemList_Malformed.dat)
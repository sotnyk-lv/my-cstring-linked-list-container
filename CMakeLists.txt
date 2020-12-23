cmake_minimum_required(VERSION 3.17)
project(linked_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(linked_list Main.cpp MyLinkedListCyclic.cpp MyLinkedListCyclic.h)
#add_executable(linked_list Main.cpp MyLinkedList.h MyLinkedList.cpp)
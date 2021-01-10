cmake_minimum_required(VERSION 3.17)
project(linked_list)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

#add_executable(linked_list src/main.cpp src/linked_cyclic_list/my_linked_cyclic_list.cpp src/linked_cyclic_list/my_linked_cyclic_list.h)

#add_subdirectory()
#add_executable(linked_list Main.cpp MyLinkedList.h MyLinkedList.cpp)
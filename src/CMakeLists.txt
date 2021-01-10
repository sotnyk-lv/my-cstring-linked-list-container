set(SOURCES linked_cyclic_list/my_linked_cyclic_list.cpp linked_cyclic_list/my_linked_cyclic_list.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SOURCES})




#set(BINARY ${CMAKE_PROJECT_NAME})
#
#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
#
#set(SOURCES ${SOURCES})
#
#add_executable(${BINARY}_run ${SOURCES})
#
#add_library(${BINARY}_lib STATIC ${SOURCES})
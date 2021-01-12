set(SOURCES linked_cyclic_list/my_linked_cyclic_list.cpp linked_cyclic_list/my_linked_cyclic_list.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SOURCES})
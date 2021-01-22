set(BINARY ${CMAKE_PROJECT_NAME}_test)

#set(SOURCES main.cpp
#        linked_list_cyclic_test/basic_tests.cpp
#        linked_list_cyclic_test/list_creation_tests.cpp
#        linked_list_cyclic_test/)

file(GLOB tests_SRC CONFIGURE_DEPENDS "linked_list_cyclic_test/*.cpp")

set(SOURCES main.cpp ${tests_SRC})

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

add_test(NAME ${BINARY} COMMAND ${BINARY})
cmake_minimum_required(VERSION 2.8)
project(linked_list)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


set(SRCS
src/linked_list.cpp
)
add_library(linked_list ${SRCS})

include_directories(src)

set(TEST_SRCS
test/all.cpp
)
add_executable(all ${TEST_SRCS})
target_link_libraries(all linked_list)

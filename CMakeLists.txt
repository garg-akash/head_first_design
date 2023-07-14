cmake_minimum_required(VERSION 3.5)
project(state_pattern)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)

add_executable(test chapter10_state_pattern.cpp)
target_link_libraries(test statelib)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(statelib SHARED state_pattern_header.cpp)
target_link_libraries(statelib)	
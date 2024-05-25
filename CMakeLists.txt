cmake_minimum_required(VERSION 3.29.3)

project(FlowState VERSION 0.0.2)

add_executable(FlowState src/main.cpp)
target_include_directories(FlowState PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

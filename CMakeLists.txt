cmake_minimum_required(VERSION 3.29.3)

project(FlowState VERSION 0.0.2)

# Add the executable
add_executable(FlowState src/main.cpp)

# Include directories
target_include_directories(FlowState PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find the SDL2 and SDL2_mixer packages
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Link SDL2 and SDL2_mixer libraries
target_link_libraries(FlowState SDL2::SDL2 SDL2_mixer::SDL2_mixer)

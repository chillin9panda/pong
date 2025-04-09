cmake_minimum_required(VERSION 3.16)

project(pong)

set(CMAKE__CXX_STANDARD 23)

find_package(SDL3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(pong
  src/game.cpp
  src/window.cpp
  main.cpp
)

target_link_libraries(pong SDL3::SDL3)

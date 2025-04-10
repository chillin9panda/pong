cmake_minimum_required(VERSION 3.16)

project(pong)

set(CMAKE__CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/include)


find_package(SDL3 REQUIRED)

add_executable(pong
  src/game.cpp
  src/window.cpp
  main.cpp
)

target_link_libraries(pong SDL3::SDL3)

if(WIN32)
  message(STATUS "compiling for windows")
elseif(UNIX AND NOT APPLE)
  message(STATUS "compiling for linux")
endif()

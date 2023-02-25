cmake_minimum_required(VERSION 3.12)
project(Pird)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(pird ${SRC})

target_include_directories(pird PUBLIC "include")
cmake_minimum_required(VERSION 3.7)
project(runtime)

#include headers and sources
include_directories(include /usr/local/include)

#compiler location
set(CMAKE_C_COMPILER  "/usr/bin/clang")
set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")

#include c++17 standard
set(CMAKE_CXX_FLAGS "-std=c++1z -fPIC -g -Wall -pedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#use clang toolchain
set(CMAKE_LINKER_FLAGS "-stdlib=libc++ -lc++abi")

#include compilation database for youcompleteme
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

#include yaml database for clang-include fixer

#file(COPY /home/carlo/Dropbox/cpp/find_all_symbols_db.yaml
#DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})


#add queue benchmark
add_executable(queue_bench ../tests/queue_bench.cpp)
target_link_libraries(queue_bench pthread benchmark)


#add runtime executable
add_executable(runtime ../src/main.cpp)
target_link_libraries(runtime pthread fmt)

#file(COPY ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
#	DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})




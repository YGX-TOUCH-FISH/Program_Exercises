cmake_minimum_required(VERSION 3.17)
project(Member_Manager)

set(CMAKE_CXX_STANDARD 14)

add_executable(Member_Manager main.cpp Member_message.h Member_block.h Member_block.cpp Member_message.cpp Member_system.h Member_system.cpp)
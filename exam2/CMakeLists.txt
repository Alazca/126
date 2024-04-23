cmake_minimum_required(VERSION 3.20)
project(a)
set(CMAKE_C_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lm -Wall -O3")
include_directories(HEADER_FILES)
file(GLOB MAIN
    "*.cpp"
    "*.hpp"
)
add_executable(${PROJECT_NAME} ${MAIN})

cmake_minimum_required(VERSION 3.20)
project(cpp_console_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp_console_test
    src/main.cpp
    src/quiz.cpp
)

target_include_directories(cpp_console_test PRIVATE src)

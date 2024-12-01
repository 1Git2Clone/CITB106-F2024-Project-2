cmake_minimum_required(VERSION 3.10)
project(CITB106-F2024-Project-2)

set(CMAKE_CXX_STANDARD 17)

add_executable(main_exec src/main.cpp)

add_executable(test_exec test/main.cpp)

enable_testing()

add_test(NAME Main COMMAND test_exec)

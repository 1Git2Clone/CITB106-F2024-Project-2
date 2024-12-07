cmake_minimum_required(VERSION 3.14)
project(CITB106-F2024-Project-2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp)

# ---
# Gtest integration based on:
# https://google.github.io/googletest/quickstart-cmake.html
# ---

include(FetchContent)

FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

if(WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(gtest)
# ---

find_package(GTest REQUIRED)

enable_testing()
add_subdirectory(test test)

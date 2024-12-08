cmake_minimum_required(VERSION 3.14)
project(CITB106-F2024-Project-2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
add_compile_options(-std=c++20)
if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")

add_executable(
  main
  ${SOURCES}
)

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

if(MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(gtest)
# ---

enable_testing()
add_subdirectory(test test)

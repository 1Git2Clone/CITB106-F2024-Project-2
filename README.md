# CITB106-F2024-Project-2

[![Build Icon]][Build Status]&emsp;[![License Icon]][LICENSE]

[Build Icon]: https://img.shields.io/github/actions/workflow/status/1git2clone/CITB106-F2024-Project-2/cmake-single-platform.yml?branch=main
[Build Status]: https://github.com/1git2clone/CITB106-F2024-Project-2/actions?query=branch%3Amain
[License Icon]: https://img.shields.io/badge/license-MIT-blue.svg
[LICENSE]: LICENSE

University project mainly involving [Mersenne numbers](https://en.wikipedia.org/wiki/Mersenne_prime).

## Setting up

The project requires [`cmake`](https://cmake.org/) to setup conventionally
(_but you can also just use plain `clang++` or `g++` to get it working_).

### Via CMake

```sh
cmake -B build
cmake --build build
./build/test/all_tests
ctest  # This is an alternative but since this project uses gtest, the display
       # of the tests will be worse.
```

### Manually

If you want to manually make your executables then you can just use a compiler
like `clang++` or `g++` (substituting for `<compiler>`) like so:

```sh
<compiler> ./src/main.cpp -O3 -Wall  # for the main executable.
<compiler> ./test/main.cpp -O3 -Wall  # for the test executable.
```

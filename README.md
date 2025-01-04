# CITB106-F2024-Project-2

[![Build Icon]][Build Status]&emsp;[![License Icon]][LICENSE]

[Build Icon]: https://img.shields.io/github/actions/workflow/status/1Git2Clone/CITB106-F2024-Project-2/cmake-linux.yml?branch=main
[Build Status]: https://github.com/1git2clone/CITB106-F2024-Project-2/actions?query=branch%3Amain
[License Icon]: https://img.shields.io/badge/license-MIT-blue.svg
[LICENSE]: LICENSE

University project mainly involving [Mersenne numbers](https://en.wikipedia.org/wiki/Mersenne_prime).

## Setting up

### Initial

> [!NOTE]
> This step needs to be done with every code change.

```sh
cmake -B build
cmake --build build
```

### Running main

```sh
./build/main
```

Alternatively, if you want to pipe user input you can do it like so:

#### On Linux/Mac OS

```sh
./build/main < ./input/mock_input.txt
```

#### On Windows

##### PowerShell

```powershell
Get-Content ./input/mock_input.txt | ./build/main
```

##### CMD

```cmd
.\build\main < .\input\mock_input.txt
```

### Running tests

```sh
./build/test/all_tests
ctest  # This is an alternative but since this project uses gtest, the display
       # of the tests will be worse.
```

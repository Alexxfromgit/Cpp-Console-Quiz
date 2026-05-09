# C++ Console Quiz

A simple C++ knowledge quiz running in the console. Covers basic C++ concepts: syntax, loops, conditionals, operators, and more.

## Build

Requires CMake 3.20+ and a C++17-compatible compiler.

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/cpp_console_test
```

## Project Structure

```
.
├── CMakeLists.txt
├── README.md
└── src/
    ├── main.cpp       # Entry point
    ├── quiz.h         # Quiz and Question declarations
    └── quiz.cpp       # Quiz implementation
```

## Scoring

Each question awards +1 for the correct answer, 0 for a neutral answer, and -1 for a wrong answer. Final score is out of 12.

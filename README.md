# CMake Hello World Example

The purpose of this repository is to show how to set up a tiny C++ project
with one source file with the C++20 standard.

## How to Build

Install with your package manager:

- `cmake`
- C++ compiler: Clang or GCC
- GNU Make or Ninja

Then run the following commands:

```console
mkdir build
cd build
cmake ..
make
```

To use Ninja instead of GNU Make, run:

```console
cmake .. -G Ninja
ninja
```

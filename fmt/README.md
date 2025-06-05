# fmt

Hello world for the library `{fmt}` using cmake-conan for conan 2.

## Validation of the conan profile

Check the available conan profiles:

```shell
conan profile list
```
out
```
default
debug
```

Check that the Debug profile exists, otherwise, create it:

```shell
conan profile show -pr=debug
```
out
```
build_type=Debug
```

## Build from console

```shell
mkcd build
cmake -B ./ -S ../ -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=~/code/hub/libraries_tests_cpp/cmake/conan_provider.cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja
cmake --build .
./fmt_cpp 
```

Expected output

    Hello, {fmt} 11 with cmake-conan 2.0!


## Build In CLion

Option 1: Use the conan plugin.
Search fmt. Select Use in this project. This will create a `conanfile.py`

Option 2:
Using the `conanfile.txt` with only the `CMakeDeps` generator, and the `cmake_layout`:

```text
[requires]
  fmt/11.2.0

[generators]
  CMakeDeps

[layout]
  cmake_layout
```

The following variables must be defined before calling the `project()` instruction,
so they must be added to the "CMake options" in the "cmake profile" via Settings.

```shell
-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="path/to/conan_provider.cmake"
-DCONAN_COMMAND="/path/to/.venv/bin/conan"
```

e.g.

```shell
-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="../cmake/conan_provider.cmake"
-DCONAN_COMMAND="/home/user/to/.venv/bin/conan"
```

See [conan-clion-plugin](https://blog.conan.io/introducing-new-conan-clion-plugin/)

Then, the cmake project can be loaded as usual.

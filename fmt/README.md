# fmt

## Build from console

```shell
mkcd build
conan install .. --build=missing --output-folder=. --profile=debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . 
./fmt_cpp 
```

Expected output

    Hello, {fmt} 11!


## Build In CLion

Check the conan profile:

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

Load the CMake Project

Run conan install:
```shell
conan install .. --build=missing --output-folder=. --profile=debug
```

Reload the CMake Project. 
Now, the CMakeUserPresets.json file contains:

```
"include": [
    "cmake-build-debug/build/Debug/generators/CMakePresets.json"
  ]
```

Build: Ctrl + F9

Run: Ctrl + F10

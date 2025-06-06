# scnlib Scan Lib

`scnlib` is a modern C++ library for scanning values. 
Think of it as a more C++-y scanf, or the inverse of {fmt} / std::format.  
See [scnlib github](https://github.com/eliaskosunen/scnlib)  
See [version 1.x](https://v1.scnlib.dev/en/master/)  
See [version 2.x](https://www.scnlib.dev/)requires gcc > 11


## Build

```shell
mkcd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=~/code/hub/libraries_tests_cpp/cmake/conan_provider.cmake -G Ninja
cmake --build .
./scanlib_cpp 
```

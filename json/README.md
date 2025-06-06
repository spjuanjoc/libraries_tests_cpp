# nlohmann_json

Hello world for the library `nlohmann json` using cmake-conan for conan 2.
JSON for modern C++
See [nlohmann github](https://github.com/nlohmann/json)
and
[json.nlohmann](https://json.nlohmann.me/)


## Build

```shell
mkcd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=~/code/hub/libraries_tests_cpp/cmake/conan_provider.cmake -G Ninja
cmake --build .
./json_cpp 
```

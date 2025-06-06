# Linear Algebra

Libraries for Linear Algebra, before std::linalg C++26

| Library   | Package Name | Version | Docs                                                           |
|:----------|:-------------|:-------:|:---------------------------------------------------------------|
| Armadillo | Armadillo    | 12.6.4  | [arma](https://arma.sourceforge.net/)                          |
| Eigen     | Eigen3       |  3.4.0  | [eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) |
| openBLAS  | OpenBLAS     |   --    | [openblas](https://www.openblas.net/)                          |


## Build

```shell
mkcd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=~/code/hub/libraries_tests_cpp/cmake/conan_provider.cmake -G Ninja
cmake --build .
./linear_algebra 
```

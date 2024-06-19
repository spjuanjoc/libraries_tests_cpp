cmake_minimum_required(VERSION 3.28)

project(linear_algebra
  VERSION "1.0.0"
  DESCRIPTION "libraries for linear algebra"
  LANGUAGES CXX
)

# Options
option(ENABLE_WERROR   "Treat compiler warnings as errors" False)


# GLOB source files
file(GLOB_RECURSE
  SOURCE_FILES
    main.cpp
)


## Set the project as an executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


## Compiler options
include(../cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})


## Setup Conan < 2.0
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake"
  )
endif ()


include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_autodetect(settings)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE conanfile.txt
  BASIC_SETUP NO_OUTPUT_DIRS
  BUILD missing
  SETTINGS ${settings}
)



## Find third-party packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
find_package(fmt REQUIRED)
find_package(Armadillo REQUIRED)
find_package(Eigen3 REQUIRED)
#find_package(OpenBLAS REQUIRED)


## Target
target_include_directories(${PROJECT_NAME}
  SYSTEM PRIVATE # These directories must be placed before other non-system directories
    ${fmt_INCLUDE_DIRS}
    ${Armadillo_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS}
#    ${OpenBLAS_INCLUDE_DIRS}
  PUBLIC
    include
)


target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${fmt_LIBRARIES}
    ${Armadillo_LIBRARIES}
    ${Eigen3_LIBRARIES}
#    ${OpenBLAS_LIBRARIES}
)


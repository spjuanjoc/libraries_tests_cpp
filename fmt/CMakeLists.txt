cmake_minimum_required(VERSION 3.28)

project(fmt_cpp
  VERSION "1.0.0"
  DESCRIPTION "fmt 11 with CMake in CLion"
  LANGUAGES CXX
)


## Set the user options
option(ENABLE_WERROR   "Treat compiler warnings as errors" False)


# GLOB the source files
file(GLOB_RECURSE
  SOURCE_FILES
    main.cpp
)


## Set the project as an executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


## Add compiler options
include(../cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})


## Find third-party libraries
find_package(fmt REQUIRED)


## Configure target options
target_include_directories(${PROJECT_NAME}
  SYSTEM PRIVATE # These directories must be placed before other non-system directories
    ${fmt_INCLUDE_DIRS}
  PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${fmt_LIBRARIES}
)

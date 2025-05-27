cmake_minimum_required(VERSION 3.22.1)

project(signals_cpp
  VERSION "0.0.1"
  DESCRIPTION "Signals and slots in C++"
  LANGUAGES CXX
)

# Options
option(ENABLE_WERROR   "Treat compiler warnings as errors" False)

## Set the project as an executable target
add_executable(${PROJECT_NAME} src/main.cpp)


## Compiler options
include(../cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})

## Find third-party packages for conan > 2
set(TOOLCHAIN_FILE_PATH ${CMAKE_BINARY_DIR}/build/${CMAKE_BUILD_TYPE}/generators)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE} ${TOOLCHAIN_FILE_PATH}/conan_toolchain.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${TOOLCHAIN_FILE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${TOOLCHAIN_FILE_PATH})

find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(sigc++-3 REQUIRED)
find_package(signals-light REQUIRED)

## Target
target_include_directories(${PROJECT_NAME}
  SYSTEM PRIVATE # These directories must be placed before other non-system directories
    ${Boost_INCLUDE_DIRS}
    ${fmt_INCLUDE_DIRS}
    ${scn_INCLUDE_DIRS}
    ${sigc++-3_INCLUDE_DIRS}
    ${signals-light_INCLUDE_DIRS}
  PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${Boost_LIBRARIES}
    ${fmt_LIBRARIES}
    ${sigc++-3_LIBRARIES}
    ${signals-light_LIBRARIES}
)


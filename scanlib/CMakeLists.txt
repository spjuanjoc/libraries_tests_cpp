cmake_minimum_required(VERSION 3.28)

project(scanlib
  VERSION "1.0.0"
  DESCRIPTION "scnlib: scanf for modern C++"
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


## Find third-party packages for conan > 2
set(TOOLCHAIN_FILE_PATH ${CMAKE_BINARY_DIR}/build/${CMAKE_BUILD_TYPE}/generators)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_TOOLCHAIN_FILE} ${TOOLCHAIN_FILE_PATH}/conan_toolchain.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${TOOLCHAIN_FILE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${TOOLCHAIN_FILE_PATH})

find_package(fmt REQUIRED)
find_package(scn REQUIRED)


## Target
target_include_directories(${PROJECT_NAME}
  SYSTEM PRIVATE # These directories must be placed before other non-system directories
    ${fmt_INCLUDE_DIRS}
    ${scn_INCLUDE_DIRS}
  PUBLIC
    include
)


target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${fmt_LIBRARIES}
    ${scn_LIBRARIES}
)


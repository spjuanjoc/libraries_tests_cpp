cmake_minimum_required(VERSION 3.22.1)

project(signals_cpp
  VERSION "0.0.1"
  DESCRIPTION "Signals and slots in C++"
  LANGUAGES CXX
)


## Set the project as an executable target
add_executable(${PROJECT_NAME} src/main.cpp)


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
find_package(Boost REQUIRED)
find_package(fmt REQUIRED)
find_package(sigc++-3 REQUIRED)
find_package(signals-light REQUIRED)

## Target
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${Boost_LIBRARIES}
    ${fmt_LIBRARIES}
    ${sigc++-3_LIBRARIES}
    ${signals-light_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    include
  SYSTEM PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${sigc++-3_INCLUDE_DIRS}
    ${signals-light_INCLUDE_DIRS}
)

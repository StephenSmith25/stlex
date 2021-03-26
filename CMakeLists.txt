project(Test)
cmake_minimum_required(VERSION 3.15)


set(CMAKE_CXX_STANDARD 14)

# Include Conan Packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(timer)
add_subdirectory(for_each)


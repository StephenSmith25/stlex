project(Test)
cmake_minimum_required(VERSION 3.15)


set(CMAKE_CXX_STANDARD 14)

# Include Conan Packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(timer)
add_subdirectory(for_each)
add_subdirectory(find)
add_subdirectory(reduce)
add_subdirectory(sort)
add_subdirectory(transform)
add_subdirectory(count)
add_subdirectory(none_of)

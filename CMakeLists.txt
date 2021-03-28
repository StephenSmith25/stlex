project(Test)
cmake_minimum_required(VERSION 3.15)


set(CMAKE_CXX_STANDARD 14)


# The conan package of goooglebenchmark segfaults - so lets use fetch content
include(FetchContent)
set(BENCHMARK_ENABLE_TESTING "OFF")
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        )
        
FetchContent_MakeAvailable(googlebenchmark)





# Include Conan Packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(timer)
add_subdirectory(for_each)
add_subdirectory(find)
add_subdirectory(reduce)
add_subdirectory(sort)
add_subdirectory(transform)
add_subdirectory(count)
add_subdirectory(none_of)
add_subdirectory(false_sharing)
add_subdirectory(cache_friendly)
add_subdirectory(atomic)

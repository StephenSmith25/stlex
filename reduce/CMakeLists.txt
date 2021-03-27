add_executable(reduce main.cpp)
target_link_libraries(reduce PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl benchmark::benchmark)

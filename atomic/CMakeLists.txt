add_executable(atomic main.cpp)
target_link_libraries(atomic PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl benchmark::benchmark)
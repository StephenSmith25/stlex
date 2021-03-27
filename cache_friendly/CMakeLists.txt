add_executable(cache_friendly main.cpp)
target_link_libraries(cache_friendly PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

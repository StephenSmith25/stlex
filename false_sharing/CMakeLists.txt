add_executable(false_sharing main.cpp)
target_link_libraries(false_sharing PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl benchmark::benchmark)
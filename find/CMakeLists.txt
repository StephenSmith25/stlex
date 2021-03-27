add_executable(find main.cpp)
target_link_libraries(find PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

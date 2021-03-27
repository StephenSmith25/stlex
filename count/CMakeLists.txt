add_executable(count main.cpp)
target_link_libraries(count PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

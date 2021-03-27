add_executable(none_of main.cpp)
target_link_libraries(none_of PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

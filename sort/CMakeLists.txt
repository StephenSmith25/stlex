add_executable(sort main.cpp)
target_link_libraries(sort PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

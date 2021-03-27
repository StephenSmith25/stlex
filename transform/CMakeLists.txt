add_executable(transform main.cpp)
target_link_libraries(transform PUBLIC timer PRIVATE CONAN_PKG::tbb CONAN_PKG::onedpl)

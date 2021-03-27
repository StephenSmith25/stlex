add_executable(for_each main.cpp)
target_link_libraries(for_each PUBLIC timer PRIVATE CONAN_PKG::tbb Threads::Threads CONAN_PKG::onedpl benchmark::benchmark)
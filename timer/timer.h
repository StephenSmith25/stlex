#include <chrono>
#include <iostream>

namespace timer {
void print_time_taken(std::chrono::high_resolution_clock::time_point t1,
                      std::chrono::high_resolution_clock::time_point t2);
std::chrono::high_resolution_clock::time_point record_time();
} // namespace timer
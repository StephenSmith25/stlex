#include "timer.h"

namespace timer {

void print_time_taken(std::chrono::high_resolution_clock::time_point t1,
                      std::chrono::high_resolution_clock::time_point t2) {
  std::cout
      << "Algorithm took: "
      << std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
             t2 - t1)
             .count()
      << " to run"
      << "\n";
}

std::chrono::high_resolution_clock::time_point record_time() {
  return std::chrono::high_resolution_clock::now();
}
} // namespace timer

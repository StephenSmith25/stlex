#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>
#include <pstl/numeric>
#include <vector>

int NUMPOINTS = 100000000;

// Finding a point in a vector
int main() {
  std::vector<int> vec(NUMPOINTS);
  std::iota(vec.begin(), vec.end(), 0);

  auto t1 = timer::record_time();
  auto num = std::count(pstl::execution::par, vec.begin(), vec.end(), 111);
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  auto num2 = std::count(pstl::execution::seq, vec.begin(), vec.end(), 114);
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);
  // My timings
  // Algorithm took: 0.120009 to run - par
  // Algorithm took: 0.88663 to run - seq
  return 0;
}

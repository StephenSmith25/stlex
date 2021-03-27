#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>
#include <pstl/numeric>
#include <vector>

int NUMPOINTS = 100000000;

// Finding a point in a vector
int main() {
  std::vector<double> vec(NUMPOINTS, 0.5);

  auto t1 = timer::record_time();
  auto result = std::reduce(pstl::execution::par, vec.begin(), vec.end());
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  auto result1 = std::reduce(pstl::execution::seq, vec.begin(), vec.end());
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  auto t5 = timer::record_time();
  double result2 = std::accumulate(vec.begin(), vec.end(), 0.0);
  auto t6 = timer::record_time();
  timer::print_time_taken(t5, t6);

  // My timings
  // Algorithm took: 0.137199 to run - par
  // Algorithm took: 0.965841 to run - seq
  // Algorithm took: 0.584989 to run - accumulate

  return 0;
}

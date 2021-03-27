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

  // make some copies fo the vectors
  auto v1 = vec;
  auto v2 = vec;

  auto lambda = [](auto &i) { return i * 3 + 4; };

  auto t1 = timer::record_time();
  std::transform(pstl::execution::par, v1.begin(), v1.end(), v1.begin(),
                 lambda);
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  std::transform(pstl::execution::seq, v2.begin(), v2.end(), v2.begin(),
                 lambda);
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  // My timings
  // Algorithm took: 0.155197 to run
  // Algorithm took: 1.05894 to run

  return 0;
}

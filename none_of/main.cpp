#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>
#include <pstl/numeric>
#include <vector>

int NUMPOINTS = 1000000000;

// Finding a point in a vector
int main() {
  std::vector<int> vec(NUMPOINTS);
  std::iota(vec.begin(), vec.end(), 0);
  std::random_shuffle(vec.begin(), vec.end());

  auto lambda = [](auto i) { return i == 1000000000 / 2; };
  auto t1 = timer::record_time();
  auto b1 = std::none_of(pstl::execution::par, vec.begin(), vec.end(), lambda);
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  auto b2 = std::none_of(pstl::execution::seq, vec.begin(), vec.end(), lambda);
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  // My timings
  // Algorithm took: 0.38995 to run
  // Algorithm took: 3.00183 to run
  return 0;
}

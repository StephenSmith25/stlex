#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>
#include <pstl/numeric>
#include <random>
#include <vector>

int NUMPOINTS = 50000000;

// Finding a point in a vector
int main() {
  std::vector<int> vec(NUMPOINTS);
  std::iota(vec.begin(), vec.end(), 0);

  std::random_shuffle(vec.begin(), vec.end());

  // make some copies fo the vectors
  auto v1 = vec;
  auto v2 = vec;

  auto t1 = timer::record_time();
  std::sort(pstl::execution::par, v1.begin(), v1.end());
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  std::sort(pstl::execution::seq, v2.begin(), v2.end());
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  // My timings
  // Algorithm took: 1.30953 to run
  // Algorithm took: 4.29197 to run

  return 0;
}

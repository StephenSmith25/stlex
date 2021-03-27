#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>
#include <tbb/task_arena.h>
#include <vector>
// get the cache line size from system (linux)

// getconf LEVEL1_DCACHE_LINESIZE
// returns 64 for me
//

// Only want to access members a
// a b and d (in the same cache line) so optimal to arrange structs with this in
// mind
struct cache_unfriendly {
  double a;
  double c[7];
  double b;
  double d;
  double e[9];
};

struct cache_friendly {
  double a;
  double b;
  double d;
  double c[7];
  double e[9];
};

int NUMPOINTS = 10000000;
int main() {
  std::vector<cache_unfriendly> cu(NUMPOINTS);
  std::vector<cache_friendly> cf(NUMPOINTS);

  auto t3 = timer::record_time();
  for (int i = 0; i < NUMPOINTS; ++i) {
    auto &s = cu[i];
    s.a += 1;
    s.b += 2;
    s.d += 4;
  }
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  auto t1 = timer::record_time();
  for (int i = 0; i < NUMPOINTS; ++i) {
    auto &s = cf[i];
    s.a += 1;
    s.b += 2;
    s.d += 4;
  }
  // cache friendly will be a bit quicker
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  return 0;
}

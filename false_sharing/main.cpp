#include "point.h"
#include "timer.h"
#include <list>
#include <pstl/algorithm>
#include <pstl/execution>
#include <tbb/task_arena.h>

// Just showing a pitfall from false sharing

int OFFSET = 8;
int NUMPOINTS = 100000000;
int main() {
  std::vector<Point> points(NUMPOINTS);
  Point testpoint(1.00, 2.00, 3.00);
  auto t1 = timer::record_time();
  double distances[16 * OFFSET];

  // offset so each distance is on its own cache line (if its a 64byte cahche
  // line)
  std::for_each(pstl::execution::par, points.begin(), points.end(),
                [&testpoint, &distances](const auto &point) {
                  int worker_index = tbb::task_arena::current_thread_index();
                  distances[worker_index * OFFSET] +=
                      Point::distance(point, testpoint);
                });
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  // Writing into distances, but not offset
  // each thread loads in the same cache line
  // but once one thraed writes into the line the cache line is invalidated
  // so need to fetch a new line, causes cache misses.
  // causes cache misses
  auto t3 = timer::record_time();
  std::for_each(pstl::execution::par, points.begin(), points.end(),
                [&testpoint, &distances](const auto &point) {
                  int worker_index = tbb::task_arena::current_thread_index();
                  distances[worker_index] += Point::distance(point, testpoint);
                });
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  return 0;
}

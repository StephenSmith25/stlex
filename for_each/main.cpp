#include "point.h"
#include "timer.h"
#include <list>
#include <pstl/algorithm>
#include <pstl/execution>

// Finding the distance from one point to loads of others
// Parallel with for_each
int NUMPOINTS = 100000000;
int main() {
  std::vector<Point> points(NUMPOINTS);
  Point testpoint(1.00, 2.00, 3.00);
  auto t1 = timer::record_time();
  std::for_each(pstl::execution::par, points.begin(), points.end(),
                [&testpoint](const auto &point) {
                  auto distance = Point::distance(point, testpoint);
                });
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  // And now why you never want to use a large list..
  // Goodbye fast access...
  std::list<Point> pointsL(NUMPOINTS);
  auto t3 = timer::record_time();
  std::for_each(pstl::execution::par, pointsL.begin(), pointsL.end(),
                [&testpoint](const auto &point) {
                  auto distance = Point::distance(point, testpoint);
                });
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  // My timings
  // 0.1956s - vector
  // 18.2831s - list

  return 0;
}

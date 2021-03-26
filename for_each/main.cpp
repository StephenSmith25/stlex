#include "point.h"
#include "timer.h"
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
  return 0;
}

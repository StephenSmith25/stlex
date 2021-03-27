#include "point.h"
#include "timer.h"
#include <pstl/algorithm>
#include <pstl/execution>

int NUMPOINTS = 100000000;

std::vector<Point> createVector() {
  std::vector<Point> points;
  points.reserve(NUMPOINTS);
  for (int i = 0; i < NUMPOINTS; i++) {
    points.emplace_back(i, i + 1, i + 2);
  }
  return points;
}

// Finding a point in a vector
int main() {
  std::vector<Point> points = createVector();
  std::random_shuffle(points.begin(), points.end());
  Point testpoint(500000, 500001, 500002);
  auto t1 = timer::record_time();
  auto it =
      std::find(pstl::execution::par, points.begin(), points.end(), testpoint);
  auto t2 = timer::record_time();
  timer::print_time_taken(t1, t2);

  auto t3 = timer::record_time();
  auto it1 =
      std::find(pstl::execution::seq, points.begin(), points.end(), testpoint);
  auto t4 = timer::record_time();
  timer::print_time_taken(t3, t4);

  // My timings
  // Algorithm took: 0.0410283s to run - par
  // Algorithm took: 0.158293s to run - seq

  return 0;
}

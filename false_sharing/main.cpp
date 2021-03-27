#include "point.h"
#include "timer.h"
#include <benchmark/benchmark.h>
#include <list>
#include <pstl/algorithm>
#include <pstl/execution>
#include <tbb/task_arena.h>

// Just showing a pitfall from false sharing
int NUMPOINTS = 1000000;

std::vector<Point> createVector() {
  std::vector<Point> points;
  points.reserve(NUMPOINTS);
  for (int i = 0; i < NUMPOINTS; ++i) {
    points.emplace_back(1.001, 2.005, 3.003);
  }
  return points;
}

void falseSharing(std::vector<Point> &points) {
  double distances[12];
  Point testpoint(1.00, 2.00, 3.00);
  std::for_each(pstl::execution::par, points.begin(), points.end(),
                [&testpoint, &distances](const auto &point) {
                  int worker_index = tbb::task_arena::current_thread_index();
                  distances[worker_index] += Point::distance(point, testpoint);
                });
}

void offset(std::vector<Point> &points) {
  double distances[12 * 8];
  Point testpoint(1.00, 2.00, 3.00);
  std::for_each(pstl::execution::par, points.begin(), points.end(),
                [&testpoint, &distances](const auto &point) {
                  int worker_index = tbb::task_arena::current_thread_index();
                  distances[worker_index * 8] +=
                      Point::distance(point, testpoint);
                });
}

static void BM_FalseSharing(benchmark::State &state) {
  auto points = createVector();
  Point testpoint(1.00, 2.00, 3.00);
  for (auto _ : state) {
    falseSharing(points);
  }
}
static void BM_Offset(benchmark::State &state) {
  auto points = createVector();
  Point testpoint(1.00, 2.00, 3.00);
  for (auto _ : state) {
    offset(points);
  }
}

BENCHMARK(BM_FalseSharing);
BENCHMARK(BM_Offset);
BENCHMARK_MAIN();
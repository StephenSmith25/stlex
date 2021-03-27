#include "point.h"
#include <benchmark/benchmark.h>
#include <list>
#include <pstl/algorithm>
#include <pstl/execution>
int NUMPOINTS = 1000000;

std::vector<Point> createVector() {
  std::vector<Point> points;
  points.reserve(NUMPOINTS);
  for (int i = 0; i < NUMPOINTS; ++i) {
    points.emplace_back(1.001, 2.005, 3.003);
  }
  return points;
}

std::list<Point> createList() {
  std::list<Point> points;
  for (int i = 0; i < NUMPOINTS; ++i) {
    points.emplace_back(1.001, 2.00, 3.00);
  }
  return points;
}

static void BM_ForEachParVec(benchmark::State &state) {
  auto points = createVector();
  Point testpoint(1.00, 2.00, 3.00);
  for (auto _ : state) {
    std::for_each(pstl::execution::par, points.begin(), points.end(),
                  [&testpoint](const auto &point) {
                    for (int i = 0; i < 1000; ++i) {
                      double a = Point::distance(point, testpoint);
                    }
                  });
  }
}

static void BM_ForEachSeqVec(benchmark::State &state) {
  auto points = createVector();
  Point testpoint(1.00, 2.00, 3.00);
  for (auto _ : state) {
    std::for_each(pstl::execution::seq, points.begin(), points.end(),
                  [&testpoint](const auto &point) {
                    for (int i = 0; i < 1000; ++i) {
                      double a = Point::distance(point, testpoint);
                    }
                  });
  }
}

static void BM_ForEachParList(benchmark::State &state) {
  auto points = createList();
  Point testpoint(1.00, 2.00, 3.00);
  for (auto _ : state) {
    std::for_each(pstl::execution::par, points.begin(), points.end(),
                  [&testpoint](const auto &point) {
                    for (int i = 0; i < 1000; ++i) {
                      double a = Point::distance(point, testpoint);
                    }
                  });
  }
}

BENCHMARK(BM_ForEachParVec);
BENCHMARK(BM_ForEachSeqVec);
BENCHMARK(BM_ForEachParList);
BENCHMARK_MAIN();
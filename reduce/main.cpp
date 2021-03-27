#include "timer.h"
#include <benchmark/benchmark.h>
#include <pstl/execution>
#include <pstl/numeric>
#include <vector>

int NUMPOINTS = 10'000'000;

double Accumulate() {
  std::vector<double> v(NUMPOINTS, 0.1);
  for (int i = 0; i < v.size(); ++i) {
    v[i] = 1.3211 * i;
  }
  double result = std::accumulate(v.begin(), v.end(), 0.0);
  return result;
}

double ParReduce() {
  std::vector<double> v(NUMPOINTS, 0.1);
  for (int i = 0; i < v.size(); ++i) {
    v[i] = 1.3211 * i;
  }
  auto result = std::reduce(pstl::execution::par, v.begin(), v.end());
  return result;
}

double SeqReduce() {
  std::vector<double> v(NUMPOINTS, 0.1);
  for (int i = 0; i < v.size(); ++i) {
    v[i] = 1.3211 * i;
  }
  auto result = std::reduce(pstl::execution::seq, v.begin(), v.end());
  return result;
}

static void BM_ParReduce(benchmark::State &state) {
  for (auto _ : state) {
    auto result = ParReduce();
    benchmark::DoNotOptimize(result);
  }
}
static void BM_SeqReduce(benchmark::State &state) {
  for (auto _ : state) {
    auto result = SeqReduce();
    benchmark::DoNotOptimize(result);
  }
}
static void BM_Accumulate(benchmark::State &state) {
  for (auto _ : state) {
    auto result = Accumulate();
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_ParReduce);
BENCHMARK(BM_SeqReduce);
BENCHMARK(BM_Accumulate);
BENCHMARK_MAIN();
#include <atomic>
#include <benchmark/benchmark.h>
#include <numeric>

#include <pstl/algorithm>
#include <pstl/execution>

int NUMELEMENTS = 1'000'000;

void TestFuncPar() {
  std::atomic<int> sum{0};
  std::vector<int> v(NUMELEMENTS);
  std::iota(v.begin(), v.end(), 0);
  std::for_each(pstl::execution::par, std::begin(v), std::end(v), [&](int i) {
    sum.fetch_add(i * i, std::memory_order_relaxed);
  });
}
void TestFuncPar1() {
  std::atomic<int> sum{0};
  std::vector<int> v(NUMELEMENTS);
  std::iota(v.begin(), v.end(), 0);
  std::for_each(pstl::execution::par_unseq, std::begin(v), std::end(v),
                [&](int i) { sum.fetch_add(i * i); });
}

void TestFuncSeq() {
  int sum{0};
  std::vector<int> v(NUMELEMENTS);
  std::iota(v.begin(), v.end(), 0);
  std::for_each(pstl::execution::seq, std::begin(v), std::end(v),
                [&](int i) { sum += i * i; });
}

static void BM_TestPar(benchmark::State &state) {
  for (auto _ : state) {
    TestFuncPar();
  }
}

static void BM_TestPar1(benchmark::State &state) {
  for (auto _ : state) {
    TestFuncPar();
  }
}
static void BM_TestSeq(benchmark::State &state) {
  for (auto _ : state) {
    TestFuncSeq();
  }
}

BENCHMARK(BM_TestPar);
BENCHMARK(BM_TestPar1);
BENCHMARK(BM_TestSeq);

BENCHMARK_MAIN();
#include <animal.hpp>

#include <vector>
#include <array>
#include <iostream>
#include <list>
#include <set>
#include <numeric>
#include <algorithm>
#include <functional>
#include <fibo.hpp>

static size_t fib(size_t i)
{
  if (i <= 2)
  {
    return 1;
  }
  return fib(i - 1) + fib(i - 2);
}

size_t fib2(size_t nthNumber){
  size_t previouspreviousNumber, previousNumber = 0, currentNumber = 1;

  for (int i = 1; i < nthNumber; i++)
  {
    previouspreviousNumber = previousNumber;
    previousNumber = currentNumber;
    currentNumber = previouspreviousNumber + previousNumber;
  }
  return currentNumber;
}


std::vector<size_t> fib_values_until(size_t N) {
  std::vector<size_t> v;
  v.reserve(N-1);
  for (size_t i{1}; i < N; ++i) {
    v.push_back(fib2(i));
  }
  return v;
}

size_t sum(auto it, auto end_it, size_t accum = 0) {
  for (; it != end_it; ++it) {
    accum += *it;
  }
  return accum;
}

int main()
{
  for (auto i : fibo_range{10, 5}) {
    std::cout << i << ", ";
  }
  std::cout << '\n';

  const auto r = fibo_range{10, 5};
  const auto s = sum(r.begin(), r.end(), 0);
  std::cout << s << '\n';
}
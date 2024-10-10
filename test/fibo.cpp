#include <fibo.hpp>

#include <gtest/gtest.h>

#include <vector>
#include <iterator>

TEST(IteratorComputesCorrectly, FibonacciIterator) {
  EXPECT_EQ(*fibo_range::fibo{1}, 1);
  EXPECT_EQ(*fibo_range::fibo{2}, 1);
  EXPECT_EQ(*fibo_range::fibo{3}, 2);
}

TEST(IteratorIterates, FibonacciIterator) {
  fibo_range r {4};
  std::vector<size_t> v;
  std::copy(r.begin(), r.end(), std::back_inserter(v));
  EXPECT_EQ(v, (std::vector<size_t>{1, 1, 2, 3}));
}

#include <fibo.hpp>

#include <gtest/gtest.h>

TEST(IteratorIterates, FibonacciIterator) {
  fibo_range r {3};
  auto it {r.begin()};
  EXPECT_NE(it, r.end());
  EXPECT_EQ(*it, 1);
}

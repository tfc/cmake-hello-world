#include <animal.hpp>

#include <vector>
#include <array>
#include <iostream>
#include <list>
#include <set>
#include <numeric>
#include <algorithm>
#include <functional>

static bool is_even(int n) { return n % 2 == 0; }

void gather(auto it, auto itend, auto itmid, decltype(is_even) pred) {
  std::stable_partition(it, itmid, std::not_fn(pred));
  std::stable_partition(itmid, itend, pred);
}

int main()
{
  std::vector<int> v{1,2,3,4,5,6,8,9,10,11,12,13,14};

  gather(v.begin(), v.end(), v.begin() + (v.end()-v.begin())/2, is_even);
  
  for (auto i : v) {
    std::cout << i << ", ";
  }
  std::cout << '\n';
}
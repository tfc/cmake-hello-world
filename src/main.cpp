#include <iostream>
#include <string>

#include <hello.hpp>
#include <mystruct.hpp>


int main() {
  const auto x{dwd::MyStruct::create_blessed_instance(3)};
  std::cout << x << '\n';
  auto y = x;
  std::cout << y << '\n';

  std::cout << dwd::MyStruct::is_even_calculation(3) << '\n';
}

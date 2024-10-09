#include <iostream>

#include <mystring.hpp>

int main() {
  MyString s1 {"halli"};
  MyString s2 {"hallo"};

  const auto s3 = s1 + s2;

  std::cout << s3.c_str() << '\n';
}
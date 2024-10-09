#include <iostream>

#include <mystring.hpp>

MyString gp {"blubb"};

void f(MyString s) {
  gp = std::move(s);
  std::cout << "gp got string " << (gp.c_str() ? gp.c_str() : "<nix>") << '\n';
}

int main() {
  {
    MyString s1 {"hello"};
    f(std::move(s1));
    std::cout << "Lifetime of s1 ends now\n";
  }

  std::cout << "GP is still " << (gp.c_str() ? gp.c_str() : "<nix>") << '\n';
}
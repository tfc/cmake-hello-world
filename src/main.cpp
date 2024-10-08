#include <iostream>
#include <string>

#include <animal.hpp>

void tier_bespielen(const Animal& a) {
  std::cout << a.name() << " macht " << a.laut() << '\n';
  if (const Dog * d = dynamic_cast<const Dog*>(&a); 
      d != nullptr && d->is_good_boi()) {
      std::cout << a.name() << " is a good boi!\n";
  }
}

int main() {
  Animal * t {new Dog{"waldi"}};

  tier_bespielen(*t);

  delete t;
}
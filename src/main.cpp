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
  Dog waldi{"waldi"};
  Cat felix{"felix"};

  Animal * pw {&waldi};
  Animal & rw {waldi};

  pw->laut();
  rw.laut();

  tier_bespielen(waldi);
  tier_bespielen(felix);
}
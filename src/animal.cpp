#include <animal.hpp>

Animal::Animal(const std::string &n)
    : name_{n}
{
}

const std::string &Animal::name() const
{
    return name_;
}


Dog::Dog(const std::string &name) 
    : Animal{name} 
    {}

std::string Dog::laut() const {
    return std::string{"wuff"};
}

Cat::Cat(const std::string &name) 
    : Animal{name} 
    {}

std::string Cat::laut() const {
    return std::string{"miau"};
}

bool Dog::is_good_boi() const {
    return true;
}

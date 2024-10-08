#include <string>

class Animal
{
    std::string name_;

public:
    Animal(const std::string &n);
    const std::string&  name() const;

    virtual std::string laut() const = 0;
};

class Dog : public Animal {
public:
    Dog(const std::string &name);
    virtual std::string laut() const override;

    bool is_good_boi() const;
};

class Cat : public Animal {
public:
    Cat(const std::string &name);
    virtual std::string laut() const override;
};
#include <mystruct.hpp>

namespace dwd {

struct dreizehnIstDoof {};

MyStruct::MyStruct(size_t number__)
    : number_{number__}, is_even_{is_even_calculation(number__)}
{
    std::cout << "MyStruct(" << this << ") wurde erzeugt\n";
}

MyStruct::MyStruct() : MyStruct{0} {}



MyStruct &MyStruct::operator=(const MyStruct &other)
{
    std::cout << "copy from MyStruct(" << &other << ") to " << this << "\n";
    number_ = other.number_;
    is_even_ = other.is_even_;
    return *this;
}

MyStruct::~MyStruct()
{
    std::cout << "MyStruct(" << this << ") wird zerstoert\n";
}

size_t MyStruct::number() const { return number_; }
bool MyStruct::is_even() const { return is_even_; }

std::ostream& operator<<(std::ostream &os, const MyStruct &x) {
  os << "{ number = " << x.number() << ", is_even = " << x.is_even() << " }";
  return os;
}

bool MyStruct::is_even_calculation(size_t n) {
    if (n == 13) {
        throw dreizehnIstDoof{};
    }
    return n % 2 == 0;
}

MyStruct MyStruct::create_blessed_instance(size_t n) {
    if (n == 20) {
        throw BoeseEingabe{"20 moegen wikinger nicht"};
    }
    try {
        return MyStruct{n};
    } catch(const dreizehnIstDoof &) {
        throw BoeseEingabe{"13 moegen aberglaeubige nicht"};
    }
}

}
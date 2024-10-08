#include <cstddef>
#include <iostream>

namespace dwd {

class MyStruct
{

    size_t number_;
    bool is_even_;


    MyStruct(size_t number__);
    MyStruct();
public:
    MyStruct(const MyStruct &other) = default;

    static MyStruct create_blessed_instance(size_t);

    MyStruct &operator=(const MyStruct &other);

    static bool is_even_calculation(size_t);

    ~MyStruct();

    size_t number() const;
    bool is_even() const;
};

std::ostream& operator<<(std::ostream &os, const MyStruct &x);

}
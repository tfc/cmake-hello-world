#include <fibo.hpp>

fibo_range::fibo::fibo(size_t startnum)
{
    for (size_t i {1}; i < startnum; ++i, ++*this) {}
}


bool fibo_range::fibo::operator!=(const fibo& other) const {
    return count != other.count;
}

bool fibo_range::fibo::operator!=(const fibo_end& other) const {
    return count != other.count;
}

size_t fibo_range::fibo::operator*() const {
    return currentNumber;
}

fibo_range::fibo& fibo_range::fibo::operator++() { 
    previouspreviousNumber = previousNumber;
    previousNumber = currentNumber;
    currentNumber = previouspreviousNumber + previousNumber;
    ++count;
    return *this;
}

fibo_range::fibo_range(size_t up_to, size_t start) 
    : it{start}
    , end_it{up_to}
    {}

fibo_range::fibo fibo_range::begin() const {
    return it;
}

fibo_range::fibo_end fibo_range::end() const {
    return end_it;
}
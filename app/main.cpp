#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <type_traits>

template<typename A, typename B> struct is_same { static constexpr bool value {false}; };
template<typename A> struct is_same<A, A> { static constexpr bool value {true}; };

template<typename T1, typename T2>
T1 add(T1 a, T2 b) {
    static_assert(!is_same<double, T2>::value, "doubles sind nicht erlaubt");
    return a + b;
}

template<bool> struct boolAdapter;
template<> struct boolAdapter<true> { using X = bool; };

template<
    template<typename> typename C, 
    typename T2, 
    typename T,
    typename DONT_USE = 
      boolAdapter<
        std::is_same<std::vector<T>, C<T>>::value 
        || std::is_same<std::list<T>, C<T>>::value
      >::X
>
C<T> add(const C<T> &v, T2 b) {
    C<T> ret{v};
    ret.push_back(b);
    return ret;
}

using namespace std::string_literals;

int main()
{
    auto x = add("a"s, "b");
    //auto y = add(1, 1.0);
    auto z = add(std::vector<int>{1,2,3}, 4);
    auto w = add(std::list<int>{1,2,3}, 4);
    //auto bla = add(1, 1.0);
}
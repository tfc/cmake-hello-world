#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <type_traits>
#include <initializer_list>

template<typename A, typename B> struct is_same { static constexpr bool value {false}; };
template<typename A> struct is_same<A, A> { static constexpr bool value {true}; };

template<typename T1, typename T2>
T1 add(T1 a, T2 b) {
    static_assert(!is_same<double, T2>::value, "doubles sind nicht erlaubt");
    return a + b;
}

template<bool> struct boolAdapter;
template<> struct boolAdapter<true> { using X = bool; };

template <typename ...Ts, typename T>
static constexpr bool any_of(const T&) {
    return (std::is_same<T, Ts>::value || ...);
}

template<
    template<typename> typename C, 
    typename T2, 
    typename T,
    typename DONT_USE = 
      boolAdapter<
        any_of<std::vector<T>, std::list<T>>(C<T>{})
      >::X
>
C<T> add(const C<T> &v, T2 b) {
    C<T> ret{v};
    ret.push_back(b);
    return ret;
}

using namespace std::string_literals;

int f(auto x) { 
    std::cout << x << ", ";
    return 1;
}

template <typename ... Ts>
void print_all(const Ts& ...ts) {
    std::cout << '{';
    auto f = [](auto x) { std::cout << x << ", "; return 1; };
    (f(ts), ...);
    std::cout << "}\n";
}

int main()
{
    //auto f = [a{x}, b{y}] (int z) -> float { return a + b + z; };

    auto g = [](auto x) { 
        return [x] (auto y) { 
            return x + y; 
        }; 
    };

    std::cout << g(1)(2) << '\n';

    print_all(1, 2, "bla"); 
#if 0
    auto x = add("a"s, 'a');
    //auto y = add(1, 1.0);
    auto z = add(std::vector<int>{1,2,3}, 4);
    auto w = add(std::list<int>{1,2,3}, 4);

    constexpr bool bla = any_of<int, float>(int(123));
#endif
}
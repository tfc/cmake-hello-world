#include <optional>
#include <set>
#include <unordered_set>
#include <map>

#include <gtest/gtest.h>

std::optional<int> dividiere(int a, int b) {
    if (b == 0) { return {}; }
    return a / b;
}

TEST(dividiere, Optional) {
    auto r = dividiere(10, 2);
    EXPECT_TRUE(r);
    EXPECT_EQ(*r, 5);
    EXPECT_FALSE(dividiere(10, 0));
}

std::optional<std::tuple<int, int>> dividiere_tup(int a, int b) {
    if (b == 0) { return {}; }
    return {{a / b, a % b}};
}

TEST(dividiere_tup, Optional) {
    auto r = dividiere_tup(10, 3);
    EXPECT_TRUE(r);
    const auto& [quotient, modulo] = *r;
    EXPECT_EQ(quotient, 3);
    EXPECT_EQ(modulo, 1);
}

TEST(set, set) {
    std::unordered_set<int> s{3, 2, 1, 3};

    if (const auto& [it, success] {s.insert(10)}; success) {
        std::cout << *it << " wurde hinzugefuegt!\n";
    }

    for (const auto& i : s) {
        std::cout << i << ", ";
    }
    std::cout << '\n';
}

template <typename Idx, typename X>
using map2d = std::map<Idx, std::map<Idx, X>>;


TEST(map, map) {
    std::map<size_t, size_t> fibos {
        {1, 1},
        {2, 1},
        {3, 2}
    };
    for (const auto &[key, value] : fibos) {
        std::cout << "fibo(" << key << ") = " << value << '\n';
    }
}


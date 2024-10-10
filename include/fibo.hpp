#include <cstddef>
#include <iterator>

struct fibo_range {
    struct fibo_end { size_t count {0}; };

    class fibo {
        size_t previouspreviousNumber {0};
        size_t previousNumber {0};
        size_t currentNumber {1};
        size_t count {0};

    public:
        fibo(size_t startnum);
        fibo(size_t startnum, int);

        bool operator!=(const fibo&) const;
        bool operator!=(const fibo_end&) const;
        size_t operator*() const;
        fibo& operator++();

        using value_type = size_t;
        using reference = size_t&;
        using iterator_category = std::forward_iterator_tag;
    };

    fibo it;
    fibo end_it;

    fibo_range(size_t up_to, size_t start = 0);

    fibo begin() const;
    fibo end() const;
};

template<>
struct std::iterator_traits<fibo_range::fibo> {
    using iterator_category = std::forward_iterator_tag;
};

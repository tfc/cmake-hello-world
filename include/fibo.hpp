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

        bool operator!=(const fibo&) const;
        bool operator!=(const fibo_end&) const;
        size_t operator*() const;
        fibo& operator++();

        using value_type = size_t;
        using reference = size_t&;
        using iterator_category = std::forward_iterator_tag;
    };

    fibo it;
    fibo_end end_it;

    fibo_range(size_t up_to, size_t start = 0);

    fibo begin() const;
    fibo_end end() const;
};
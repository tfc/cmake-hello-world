#include <cstddef>
#include <memory>

class MyString {
    size_t length_ {0};
    std::unique_ptr<char[]> content_;

public:
    MyString() = default;
    MyString(const char *);
    MyString(const char *, size_t );

    MyString(const MyString &);
    MyString& operator=(const MyString &);

    MyString(MyString &&) = default;
    MyString& operator=(MyString &&) = default;

    MyString operator+(const MyString &) const;
    bool operator==(const MyString &) const;

    size_t length() const;
    const char * c_str() const;
};
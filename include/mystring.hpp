#include <cstddef>

class MyString {
    size_t length_ {0};
    char *content_ {nullptr};

public:
    MyString() = default;
    MyString(const char *);
    MyString(const char *, size_t );
    ~MyString();

    MyString(const MyString &);
    MyString& operator=(const MyString &);

    MyString(MyString &&);
    MyString& operator=(MyString &&);

    MyString operator+(const MyString &) const;
    bool operator==(const MyString &) const;

    size_t length() const;
    const char * c_str() const;
};
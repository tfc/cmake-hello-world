#include <mystring.hpp>

#include <cstring>
#include <iostream>

static std::unique_ptr<char[]> allocate_and_fill(const char *source, size_t length) {
  auto content {std::make_unique_for_overwrite<char[]>(length+1)};
  std::memcpy(content.get(), source, length+1);
  return content;
}

MyString::MyString(const char *s)
  : MyString(s, std::strlen(s))
  {}

MyString::MyString(const char *s, size_t len)
  : length_{len}
  , content_{allocate_and_fill(s, len)}
  {
    std::cout << "CTOR with " << (content_ ? content_.get() : "empty") << '\n';
  }

MyString::MyString(const MyString &other) 
  : MyString{other.content_.get(), other.length_}
  {
    std::cout << "COPY CTOR with " << (content_ ? content_.get() : "empty") << '\n';
  }


MyString& MyString::operator=(const MyString &other) {
    content_ = allocate_and_fill(other.content_.get(), other.length_);
    length_ = other.length_;

    std::cout << "OPERATOR= with " << (content_ ? content_.get() : "empty") << '\n';
    return *this;
}

size_t MyString::length() const { return length_; }
const char * MyString::c_str() const { return content_.get(); }

MyString MyString::operator+(const MyString &other) const {
    size_t len = length_ + other.length_;
    auto dest = std::make_unique_for_overwrite<char[]>(len+1);
    memcpy(dest.get(), content_.get(), length_);
    memcpy(dest.get() + length_, other.content_.get(), other.length_ + 1);
    MyString s{}; 
    s.length_ = len;
    s.content_= std::move(dest);
    return s;
}

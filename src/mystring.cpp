#include <mystring.hpp>

#include <cstring>
#include <iostream>

MyString::MyString(const char *s)
  : MyString(s, std::strlen(s))
  {}

MyString::MyString(const char *s, size_t len)
  : length_{len}
  , content_{new char[length_+1]}
  {
    std::memcpy(content_, s, length_+1);
  }

MyString::MyString(const MyString &other) 
  : MyString{other.content_, other.length_}
  {}


MyString& MyString::operator=(const MyString &other) {
    MyString{other.content_, other.length_};
    return *this;
}

MyString::~MyString() {
    std::cout << "Destroying \"" << content_ << "\"\n";
    delete[] content_;
}

size_t MyString::length() const { return length_; }
const char * MyString::c_str() const { return content_; }

MyString MyString::operator+(const MyString &other) const {
    size_t len = length_ + other.length_;
    char *dest = new char[len+1];
    memcpy(dest, content_, length_);
    memcpy(dest + length_, other.content_, other.length_ + 1);
    MyString s{}; 
    s.length_ = len;
    s.content_ = dest;
    return s;
}

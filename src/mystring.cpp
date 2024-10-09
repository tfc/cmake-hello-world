#include <mystring.hpp>

#include <cstring>
#include <iostream>

static char* allocate_and_fill(const char *source, size_t length) {
  auto content {new char[length+1]};
  std::memcpy(content, source, length+1);
  return content;
}

MyString::MyString(const char *s)
  : MyString(s, std::strlen(s))
  {}

MyString::MyString(const char *s, size_t len)
  : length_{len}
  , content_{allocate_and_fill(s, len)}
  {
    std::cout << "CTOR with " << (content_ ? content_ : "empty") << '\n';
  }

MyString::MyString(const MyString &other) 
  : MyString{other.content_, other.length_}
  {
    std::cout << "COPY CTOR with " << (content_ ? content_ : "empty") << '\n';
  }

MyString::MyString(MyString &&other) 
  : length_{other.length_}
  , content_{other.content_}
{
  std::cout << "MOVE CTOR with " << (content_ ? content_ : "empty") << '\n';
  other.content_ = nullptr;
}


MyString& MyString::operator=(const MyString &other) {
    delete[] content_;
    content_ = allocate_and_fill(other.content_, other.length_);
    length_ = other.length_;

    std::cout << "OPERATOR= with " << (content_ ? content_ : "empty") << '\n';
    return *this;
}

MyString& MyString::operator=(MyString &&other) {
    std::swap(content_, other.content_);
    std::swap(length_, other.length_);
    std::cout << "MOVE OPERATOR= with " << (content_ ? content_ : "empty") << '\n';
    return *this;
}



MyString::~MyString() {
    if (content_ != nullptr) {
      std::cout << "Destroying \"" << content_ << "\"\n";
    } else {
      std::cout << "Destroying empty string\n";
    }
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

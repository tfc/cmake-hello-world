cmake_minimum_required(VERSION 3.28)

project(HelloWorld
  VERSION 1.0
  DESCRIPTION "Hello World Project"
  LANGUAGES CXX
  )

add_executable(hello 
  src/main.cpp
  src/hello.cpp
  src/mystruct.cpp
  src/animal.cpp
  src/mystring.cpp
  src/fibo.cpp
  )
target_compile_features(hello PUBLIC cxx_std_20)

target_include_directories(hello PUBLIC include)

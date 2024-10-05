cmake_minimum_required(VERSION 3.29)

project(HelloWorld
  VERSION 1.0
  DESCRIPTION "Hello World Project"
  LANGUAGES CXX
  )

add_executable(hello src/main.cpp)
target_compile_features(hello PUBLIC cxx_std_20)

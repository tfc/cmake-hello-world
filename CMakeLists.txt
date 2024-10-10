cmake_minimum_required(VERSION 3.28)

project(HelloWorld
  VERSION 1.0
  DESCRIPTION "Hello World Project"
  LANGUAGES CXX
  )

add_library(dwdlib 
  src/hello.cpp
  src/mystruct.cpp
  src/animal.cpp
  src/mystring.cpp
  src/fibo.cpp
  )
target_compile_features(dwdlib PUBLIC cxx_std_20)
target_include_directories(dwdlib PUBLIC include)

add_executable(hello 
  app/main.cpp
  )
target_compile_features(hello PUBLIC cxx_std_20)
target_link_libraries(hello PUBLIC dwdlib)

enable_testing()
add_subdirectory(test)

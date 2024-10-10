include(CTest)

find_package(GTest REQUIRED)

add_executable(hello-gtest
  fibo.cpp
  bla.cpp
  )
target_link_libraries(hello-gtest dwdlib GTest::gtest_main)
target_compile_options(hello-gtest PRIVATE -Wall -Wextra -Werror)

include(GoogleTest)
gtest_discover_tests(hello-gtest)
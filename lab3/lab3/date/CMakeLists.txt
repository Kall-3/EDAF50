# add_executable(primes primes.cc sieve_of_eratosthenes_primes.cc)

add_executable(date_test date_test.cc date.cc)

add_executable(g_date_test g_date_test.cc date.cc)
add_executable(to_string_test to_string_test.cc to_string.cc date.cc)
add_executable(string_cast_test string_cast_test.cc date.cc)

target_link_libraries(g_date_test PRIVATE GTest::gtest_main)
target_link_libraries(to_string_test PRIVATE GTest::gtest_main)
target_link_libraries(string_cast_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(g_date_test)
gtest_discover_tests(to_string_test)
gtest_discover_tests(string_cast_test)

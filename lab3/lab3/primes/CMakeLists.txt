add_executable(primes primes.cc sieve_of_eratosthenes_primes.cc)

add_executable(prime_test prime_test.cc sieve_of_eratosthenes_primes.cc)
target_link_libraries(prime_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(prime_test)

if(EXISTS "/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/primes/prime_test[1]_tests.cmake")
  include("/home/Kojjan/Documents/School/EDAF50 - C++ Programming/lab3/build/lab3/primes/prime_test[1]_tests.cmake")
else()
  add_test(prime_test_NOT_BUILT prime_test_NOT_BUILT)
endif()

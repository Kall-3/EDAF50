#include <iostream>
#include "sieve_of_eratosthenes_primes.h"

int main () {
    // Print largest prime under 100000
    SievePrimes sp1(100000);
    std::cout << sp1.largestPrime() << std::endl;

    // Print prime numbers from 1 - 200
    SievePrimes sp2(200);
    for (auto prime : sp2.getPrimes()) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

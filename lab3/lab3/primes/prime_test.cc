#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
#include "sieve_of_eratosthenes_primes.h"

TEST(PrimeTest, PrimesUnderTenTest) {
    std::vector<int> primesUnderTen = {2, 3, 5, 7};

    SievePrimes sp(10);
    std::vector<int> sievePrimes = sp.getPrimes();

    ASSERT_EQ(primesUnderTen, sievePrimes);
}

TEST(PrimeTest, LastFivePrimesUnder_1_000) {
    std::vector<int> lastFivePrimes = {971, 977, 983, 991, 997};

    SievePrimes sp(1000);
    std::vector<int> sievePrimes = sp.getPrimes();
    std::vector<int> sieveLastFivePrimes;

    if (sievePrimes.size() >= 5) {
        std::vector<int> temp(sievePrimes.end() - 5, sievePrimes.end());
        sieveLastFivePrimes = temp;
    } else {
        throw std::invalid_argument("Did not find enough primes, list shorter than 5.");
    }

    ASSERT_EQ(lastFivePrimes, sieveLastFivePrimes);
}

TEST(PrimeTest, LargersPrimeUpto_100_000) {
    int largestPrime = 99991; // 99 991

    SievePrimes sp(100000);
    int sieveLargestPrime = sp.largestPrime();

    ASSERT_EQ(largestPrime, sieveLargestPrime);
}

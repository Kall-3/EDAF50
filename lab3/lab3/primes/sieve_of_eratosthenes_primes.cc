#include <vector>
#include <string>
#include "sieve_of_eratosthenes_primes.h"

using std::string;

SievePrimes::SievePrimes(const int roof) {
    string representation(roof + 1, 'P');

    representation.at(0) = representation.at(1) = 'C';

    for (int p = 2; p * p <= roof; p++) {
        if (representation.at(p) == 'P') {
            // Update all multiples of p
            for (int i = p * p; i <= roof; i += p) {
                representation.at(i) = 'C';
            }
        }
    }

    std::vector<int> primes = {};
    // Enumeration, to find what numbers are primes
    for (auto it = representation.begin(); it != representation.end(); ++it) {
        if (*it == 'P') {
            primes.push_back(it - representation.begin());
        }
    }

    this->primes = primes;
}

std::vector<int> SievePrimes::getPrimes() {
    return this->primes;
}

int SievePrimes::largestPrime() {
    return this->primes.back();
}

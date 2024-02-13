#include <vector>

class SievePrimes {
public:
    /* Member values */
    std::vector<int> primes;

    /* Member functions */
    SievePrimes(const int roof);
    ~SievePrimes();

    std::vector<int> getPrimes();
    int largestPrime();

private:
    
};

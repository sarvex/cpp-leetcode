/**
 * @brief Sieve of Eratosthenes for counting primes
 * @intuition Mark multiples of each prime as composite
 * @approach Classic sieve algorithm marking non-primes
 * @complexity Time: O(n log log n), Space: O(n)
 */
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto countPrimes(int n) const -> int {
    if (n < 2) {
      return 0;
    }
    std::vector<bool> isPrime(n, true);
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        ++count;
        for (long long j = static_cast<long long>(i) * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    return count;
  }
};

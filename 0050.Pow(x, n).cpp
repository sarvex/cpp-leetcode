/**
 * @brief Compute x raised to power n using fast exponentiation
 * @intuition Use binary exponentiation to compute in O(log n)
 * @approach Iteratively square base and halve exponent
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto myPow(const double x, const int n) -> double {
    auto qpow = [](double base, long long exp) -> double {
      double result = 1.0;
      while (exp != 0) {
        if ((exp & 1) != 0) {
          result *= base;
        }
        base *= base;
        exp >>= 1;
      }
      return result;
    };

    return n >= 0 ? qpow(x, n) : 1.0 / qpow(x, -static_cast<long long>(n));
  }
};

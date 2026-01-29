/**
 * @brief Divide two integers without multiplication, division, or mod
 * @intuition Use bit shifting to efficiently compute quotient
 * @approach Work with negatives to avoid overflow, double divisor using shifts
 * @complexity Time: O(log^2 n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto divide(const int dividend, const int divisor)
      -> int {
    if (divisor == 1) {
      return dividend;
    }
    if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
      return std::numeric_limits<int>::max();
    }

    const bool positive = (dividend > 0) == (divisor > 0);

    int a = dividend > 0 ? -dividend : dividend;
    int b = divisor > 0 ? -divisor : divisor;
    int result = 0;

    while (a <= b) {
      int x = b;
      int count = 1;

      while (x >= (std::numeric_limits<int>::min() >> 1) && a <= (x << 1)) {
        x <<= 1;
        count <<= 1;
      }

      result += count;
      a -= x;
    }

    return positive ? result : -result;
  }
};

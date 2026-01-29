/**
 * @brief Factor out 2, 3, 5 to check ugly number
 * @intuition Ugly numbers only have prime factors 2, 3, and 5
 * @approach Repeatedly divide by 2, 3, 5 until no longer divisible
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static constexpr auto isUgly(int n) noexcept -> bool {
    if (n < 1) {
      return false;
    }
    while (n % 2 == 0) {
      n /= 2;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    while (n % 5 == 0) {
      n /= 5;
    }
    return n == 1;
  }
};

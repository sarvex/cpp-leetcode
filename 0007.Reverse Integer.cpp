/**
 * @brief Reverse digits of a 32-bit signed integer
 * @intuition Extract digits from the end and build the reversed number
 * @approach Check for overflow before each multiplication to stay in bounds
 * @complexity Time: O(log x), Space: O(1)
 */

#include <limits>

class Solution final {
public:
  [[nodiscard]] static constexpr auto reverse(int x) noexcept -> int {
    int ans = 0;
    while (x != 0) {
      if (ans < std::numeric_limits<int>::min() / 10 ||
          ans > std::numeric_limits<int>::max() / 10) {
        return 0;
      }
      ans = ans * 10 + x % 10;
      x /= 10;
    }
    return ans;
  }
};

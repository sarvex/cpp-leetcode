/**
 * @brief Compute the integer square root of x
 * @intuition Binary search for the largest number whose square is <= x
 * @approach Use binary search with overflow-safe comparison mid > x / mid
 * @complexity Time: O(log x), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto mySqrt(int const x) -> int {
    int left = 0;
    int right = x;

    while (left < right) {
      int const mid = left + (right - left + 1) / 2;
      if (mid > x / mid) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }

    return left;
  }
};

/**
 * @brief Count distinct ways to climb n stairs taking 1 or 2 steps
 * @intuition Fibonacci sequence - ways to reach step n is sum of ways to n-1 and n-2
 * @approach Iterative DP with two variables to track previous two states
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto climbStairs(int const n) -> int {
    int a = 0;
    int b = 1;

    for (int i = 0; i < n; ++i) {
      int const c = a + b;
      a = b;
      b = c;
    }

    return b;
  }
};

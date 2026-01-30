/**
 * @brief DP for counting ways to paint fence with k colors
 * @intuition Track same-color and different-color continuations separately
 * @approach Use two states: f[i] for different color, g[i] for same color as previous
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
  [[nodiscard]] static auto numWays(const int n, const int k) -> int {
    std::vector<int> f(n);
    std::vector<int> g(n);
    f[0] = k;
    
    for (int i = 1; i < n; ++i) {
      f[i] = (f[i - 1] + g[i - 1]) * (k - 1);
      g[i] = f[i - 1];
    }
    return f[n - 1] + g[n - 1];
  }
};

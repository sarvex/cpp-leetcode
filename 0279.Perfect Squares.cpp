/**
 * @brief DP to find minimum perfect squares summing to n
 * @intuition Unbounded knapsack with perfect squares as items
 * @approach Use 2D DP where f[i][j] is min squares using first i squares to sum j
 * @complexity Time: O(sqrt(n) * n), Space: O(sqrt(n) * n)
 */
class Solution final {
public:
  [[nodiscard]] static auto numSquares(const int n) -> int {
    const int m = static_cast<int>(std::sqrt(n));
    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, INT_MAX / 2));
    f[0][0] = 0;
    
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        f[i][j] = f[i - 1][j];
        if (j >= i * i) {
          f[i][j] = std::min(f[i][j], f[i][j - i * i] + 1);
        }
      }
    }
    return f[m][n];
  }
};

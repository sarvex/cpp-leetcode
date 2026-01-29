/**
 * @brief Count unique paths from top-left to bottom-right in a grid
 * @intuition Use DP - paths to cell equals sum of paths from left and above
 * @approach Fill DP table row by row, accumulating path counts
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto uniquePaths(int const m, int const n) -> int {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i > 0) {
          dp[i][j] += dp[i - 1][j];
        }
        if (j > 0) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

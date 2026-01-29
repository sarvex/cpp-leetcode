/**
 * @brief Find minimum path sum from top-left to bottom-right
 * @intuition Each cell's minimum path is the minimum of coming from left or above plus current value
 * @approach Bottom-up DP, fill first row and column, then compute remaining cells
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto minPathSum(std::vector<std::vector<int>> const& grid) -> int {
    int const m = static_cast<int>(grid.size());
    int const n = static_cast<int>(grid[0].size());
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; ++j) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

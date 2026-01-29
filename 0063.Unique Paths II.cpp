/**
 * @brief Count unique paths with obstacles in the grid
 * @intuition Use memoization, obstacles block all paths through them
 * @approach Top-down DP with obstacle checking at each cell
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto uniquePathsWithObstacles(
      std::vector<std::vector<int>> const& obstacleGrid) -> int {
    int const m = static_cast<int>(obstacleGrid.size());
    int const n = static_cast<int>(obstacleGrid[0].size());
    std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

    auto dfs = [&](auto&& self, int const i, int const j) -> int {
      if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
        return 0;
      }
      if (i == m - 1 && j == n - 1) {
        return 1;
      }
      if (memo[i][j] == -1) {
        memo[i][j] = self(self, i + 1, j) + self(self, i, j + 1);
      }
      return memo[i][j];
    };

    return dfs(dfs, 0, 0);
  }
};

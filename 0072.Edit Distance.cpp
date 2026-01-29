/**
 * @brief Find minimum edit operations to transform word1 into word2
 * @intuition DP where each cell represents min edits to transform prefixes
 * @approach Build 2D table, consider insert/delete/replace operations
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto minDistance(std::string const& word1, std::string const& word2)
      -> int {
    int const m = static_cast<int>(word1.size());
    int const n = static_cast<int>(word2.size());
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int j = 0; j <= n; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
      }
    }

    return dp[m][n];
  }
};

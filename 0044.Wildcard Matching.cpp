/**
 * @brief Wildcard pattern matching with '?' and '*' support
 * @intuition Use memoization to avoid recomputing subproblems
 * @approach DFS with memoization - '*' matches zero or more characters
 * @complexity Time: O(m * n), Space: O(m * n)
 */

class Solution final {
public:
  [[nodiscard]] static auto isMatch(const std::string& s,
                                    const std::string& p) -> bool {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(p.size());
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));

    auto dfs = [&](auto&& self, int i, int j) -> bool {
      if (i >= m) {
        return j >= n || (p[j] == '*' && self(self, i, j + 1));
      }
      if (j >= n) {
        return false;
      }
      if (memo[i][j] != -1) {
        return memo[i][j] == 1;
      }

      bool result = false;
      if (p[j] == '*') {
        result = self(self, i + 1, j) || self(self, i, j + 1);
      } else {
        result = (p[j] == '?' || s[i] == p[j]) && self(self, i + 1, j + 1);
      }

      memo[i][j] = result ? 1 : 0;
      return result;
    };

    return dfs(dfs, 0, 0);
  }
};

/**
 * @brief Wildcard pattern matching with '?' and '*' support
 * @intuition Use memoization to avoid recomputing subproblems
 * @approach DFS with memoization - '*' matches zero or more characters
 * @complexity Time: O(m * n), Space: O(m * n)
 */

#include <cstring>
#include <string>

class Solution final {
public:
  [[nodiscard]] auto isMatch(const std::string& s,
                             const std::string& p) const -> bool {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(p.size());
    int memo[m + 1][n + 1];
    std::memset(memo, -1, sizeof(memo));

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

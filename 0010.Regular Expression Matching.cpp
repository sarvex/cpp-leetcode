#include <string_view>
#include <vector>

class Solution final {
public:
  /**
   * @brief Regular expression matching with support for '.' and '*'.
   * @intuition Use recursion with memoization to efficiently match string and
   * pattern.
   * @approach Top-down DP (recursion + memo) using std::vector and string_view
   * for clarity and performance.
   * @complexity Time: O(m*n), Space: O(m*n), where m = s.size(), n = p.size().
   */
  [[nodiscard]] bool isMatch(std::string s, std::string p) const {
    const auto m = s.size(), n = p.size();
    std::vector<std::vector<std::optional<bool>>> memo(
        m + 1, std::vector<std::optional<bool>>(n + 1));
    const auto sv = std::string_view{s};
    const auto pv = std::string_view{p};

    auto match = [&](auto &&self, size_t i, size_t j) -> bool {
      if (memo[i][j].has_value())
        return memo[i][j].value();
      if (j == n)
        return memo[i][j] = (i == m);
      const bool firstMatch = (i < m) && (sv[i] == pv[j] || pv[j] == '.');
      bool res = false;
      if (j + 1 < n && pv[j + 1] == '*') {
        res = self(self, i, j + 2) || (firstMatch && self(self, i + 1, j));
      } else {
        res = firstMatch && self(self, i + 1, j + 1);
      }
      return memo[i][j] = res;
    };
    return match(match, 0, 0);
  }
};

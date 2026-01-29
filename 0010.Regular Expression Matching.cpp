/**
 * @brief Regular expression matching with support for '.' and '*'
 * @intuition Use recursion with memoization to efficiently match string and pattern
 * @approach Top-down DP using std::vector and string_view for clarity
 * @complexity Time: O(m*n), Space: O(m*n)
 */

#include <string>
#include <string_view>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto isMatch(const std::string& s, const std::string& p)
      -> bool {
    const auto m = s.size();
    const auto n = p.size();
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
    const auto sv = std::string_view{s};
    const auto pv = std::string_view{p};

    auto match = [&](auto&& self, size_t i, size_t j) -> bool {
      if (memo[i][j] != -1) {
        return memo[i][j] == 1;
      }
      if (j == n) {
        memo[i][j] = (i == m) ? 1 : 0;
        return memo[i][j] == 1;
      }

      const bool firstMatch = (i < m) && (sv[i] == pv[j] || pv[j] == '.');
      bool res = false;

      if (j + 1 < n && pv[j + 1] == '*') {
        res = self(self, i, j + 2) || (firstMatch && self(self, i + 1, j));
      } else {
        res = firstMatch && self(self, i + 1, j + 1);
      }

      memo[i][j] = res ? 1 : 0;
      return res;
    };

    return match(match, 0, 0);
  }
};

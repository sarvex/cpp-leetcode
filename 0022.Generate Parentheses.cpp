/**
 * @brief Generate all valid combinations of n pairs of parentheses
 * @intuition Use backtracking with open/close count constraints
 * @approach DFS adding '(' if open < n, ')' if close < open
 * @complexity Time: O(4^n / sqrt(n)), Space: O(n)
 */

#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto generateParenthesis(int n) const
      -> std::vector<std::string> {
    std::vector<std::string> result;
    std::string current;

    auto dfs = [&](auto&& self, int open, int close) -> void {
      if (open > n || close > n || close > open) {
        return;
      }
      if (open == n && close == n) {
        result.push_back(current);
        return;
      }

      current.push_back('(');
      self(self, open + 1, close);
      current.pop_back();

      current.push_back(')');
      self(self, open, close + 1);
      current.pop_back();
    };

    dfs(dfs, 0, 0);
    return result;
  }
};

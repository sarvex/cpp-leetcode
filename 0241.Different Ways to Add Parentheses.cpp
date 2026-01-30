/**
 * @brief Divide and conquer with memoization for expression evaluation
 * @intuition Split expression at each operator, combine all left/right results
 * @approach Recursively compute results for subexpressions, combine with operator
 * @complexity Time: O(4^n / sqrt(n)) Catalan number, Space: O(4^n / sqrt(n))
 */

class Solution final {
private:
  std::unordered_map<std::string, std::vector<int>> memo;

  [[nodiscard]] auto dfs(const std::string& expression) -> std::vector<int> {
    if (auto it = memo.find(expression); it != memo.end()) {
      return it->second;
    }
    if (expression.size() < 3) {
      return {std::stoi(expression)};
    }
    
    std::vector<int> results;
    const auto n = expression.size();
    
    for (std::size_t i = 0; i < n; ++i) {
      const char c = expression[i];
      if (c == '-' || c == '+' || c == '*') {
        auto left = dfs(expression.substr(0, i));
        auto right = dfs(expression.substr(i + 1));
        for (const int a : left) {
          for (const int b : right) {
            if (c == '-') {
              results.push_back(a - b);
            } else if (c == '+') {
              results.push_back(a + b);
            } else {
              results.push_back(a * b);
            }
          }
        }
      }
    }
    memo[expression] = results;
    return results;
  }

public:
  [[nodiscard]] auto diffWaysToCompute(const std::string& expression) -> std::vector<int> {
    return dfs(expression);
  }
};

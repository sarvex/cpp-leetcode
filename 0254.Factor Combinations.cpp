/**
 * @brief DFS backtracking for factor combinations
 * @intuition Find all ways to express n as product of factors >= 2
 * @approach Recursively find factors starting from minimum to avoid duplicates
 * @complexity Time: O(sqrt(n)^k) where k is number of factors, Space: O(k)
 */
#include <functional>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto getFactors(int n) const -> std::vector<std::vector<int>> {
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    
    std::function<void(int, int)> dfs = [&](int num, int minFactor) {
      if (!current.empty()) {
        auto combination = current;
        combination.push_back(num);
        result.push_back(combination);
      }
      for (int factor = minFactor; factor * factor <= num; ++factor) {
        if (num % factor == 0) {
          current.push_back(factor);
          dfs(num / factor, factor);
          current.pop_back();
        }
      }
    };
    
    dfs(n, 2);
    return result;
  }
};

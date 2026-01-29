/**
 * @brief Backtracking for k numbers summing to n
 * @intuition Find all combinations of k numbers from 1-9 that sum to n
 * @approach DFS with pruning based on remaining sum and count
 * @complexity Time: O(C(9,k)), Space: O(k) for recursion
 */
#include <functional>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto combinationSum3(int k, int n) const -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    
    std::function<void(int, int)> dfs = [&](int start, int remaining) {
      if (remaining == 0) {
        if (current.size() == static_cast<std::size_t>(k)) {
          result.push_back(current);
        }
        return;
      }
      if (start > 9 || start > remaining || current.size() >= static_cast<std::size_t>(k)) {
        return;
      }
      current.push_back(start);
      dfs(start + 1, remaining - start);
      current.pop_back();
      dfs(start + 1, remaining);
    };
    
    dfs(1, n);
    return result;
  }
};

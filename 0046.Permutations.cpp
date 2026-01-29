/**
 * @brief Generate all permutations of distinct integers
 * @intuition Use backtracking with visited array to track used elements
 * @approach DFS building permutation one element at a time
 * @complexity Time: O(n * n!), Space: O(n)
 */

#include <vector>

class Solution final {
public:
  [[nodiscard]] auto permute(std::vector<int>& nums) const
      -> std::vector<std::vector<int>> {
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> result;
    std::vector<int> current(n);
    std::vector<bool> visited(n, false);

    auto dfs = [&](auto&& self, int index) -> void {
      if (index == n) {
        result.emplace_back(current);
        return;
      }

      for (int j = 0; j < n; ++j) {
        if (!visited[j]) {
          visited[j] = true;
          current[index] = nums[j];
          self(self, index + 1);
          visited[j] = false;
        }
      }
    };

    dfs(dfs, 0);
    return result;
  }
};

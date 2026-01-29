/**
 * @brief Find all unique combinations that sum to target (no reuse)
 * @intuition Use backtracking, skip duplicates at same level
 * @approach Sort, DFS with duplicate skipping
 * @complexity Time: O(2^n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto combinationSum2(std::vector<int>& candidates,
                                            const int target)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(candidates);
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    const auto n = candidates.size();

    auto dfs = [&](auto&& self, size_t start, int remaining) -> void {
      if (remaining == 0) {
        result.emplace_back(current);
        return;
      }
      if (start >= n || remaining < candidates[start]) {
        return;
      }

      for (size_t j = start; j < n; ++j) {
        if (j > start && candidates[j] == candidates[j - 1]) {
          continue;
        }
        current.emplace_back(candidates[j]);
        self(self, j + 1, remaining - candidates[j]);
        current.pop_back();
      }
    };

    dfs(dfs, 0, target);
    return result;
  }
};

/**
 * @brief Find all combinations that sum to target (with repetition allowed)
 * @intuition Use backtracking, allowing reuse of same element
 * @approach DFS with sorted candidates, prune when exceeding target
 * @complexity Time: O(n^(t/m)), Space: O(t/m) where t=target, m=min element
 */

class Solution final {
public:
  [[nodiscard]] static auto combinationSum(std::vector<int>& candidates,
                                           const int target)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(candidates);
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    auto dfs = [&](auto&& self, int start, int remaining) -> void {
      if (remaining == 0) {
        result.emplace_back(current);
        return;
      }
      if (remaining < candidates[start]) {
        return;
      }

      for (size_t j = start; j < candidates.size(); ++j) {
        current.push_back(candidates[j]);
        self(self, static_cast<int>(j), remaining - candidates[j]);
        current.pop_back();
      }
    };

    dfs(dfs, 0, target);
    return result;
  }
};

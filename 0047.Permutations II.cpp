/**
 * @brief Generate all unique permutations (may contain duplicates)
 * @intuition Sort and skip duplicates at same recursion level
 * @approach Backtracking with duplicate detection
 * @complexity Time: O(n * n!), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto permuteUnique(std::vector<int>& nums)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(nums);
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
        if (visited[j] || (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1])) {
          continue;
        }
        current[index] = nums[j];
        visited[j] = true;
        self(self, index + 1);
        visited[j] = false;
      }
    };

    dfs(dfs, 0);
    return result;
  }
};

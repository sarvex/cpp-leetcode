/**
 * @brief Find all non-decreasing subsequences of length >= 2
 * @intuition DFS with pruning: skip duplicates at same decision point
 * @approach Backtrack: include if >= last element, skip if equal to last skipped
 * @complexity Time: O(2^n), Space: O(n)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto findSubsequences(const std::vector<int>& nums) const
        -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> ans;
        std::vector<int> current;
        dfs(0, -1000, current, nums, ans);
        return ans;
    }

private:
    auto dfs(int idx, int lastVal, std::vector<int>& current,
             const std::vector<int>& nums, std::vector<std::vector<int>>& ans) const -> void {
        if (idx == static_cast<int>(nums.size())) {
            if (current.size() > 1) {
                ans.push_back(current);
            }
            return;
        }

        if (nums[idx] >= lastVal) {
            current.push_back(nums[idx]);
            dfs(idx + 1, nums[idx], current, nums, ans);
            current.pop_back();
        }

        if (nums[idx] != lastVal) {
            dfs(idx + 1, lastVal, current, nums, ans);
        }
    }
};

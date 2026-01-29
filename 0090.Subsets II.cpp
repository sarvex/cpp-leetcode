/**
 * @brief Backtracking to generate all unique subsets with duplicates in input
 * @intuition Sort to group duplicates; skip consecutive duplicates when not including
 * @approach DFS with choice to include or exclude; skip duplicate elements when excluding
 * @complexity Time: O(2^n * n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto subsetsWithDup(vector<int>& nums) -> vector<vector<int>> {
        ranges::sort(nums);
        vector<vector<int>> result;
        vector<int> current;
        const int n = static_cast<int>(nums.size());
        
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i >= n) {
                result.push_back(current);
                return;
            }
            
            current.push_back(nums[i]);
            dfs(i + 1);
            current.pop_back();
            
            while (i + 1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
            dfs(i + 1);
        };
        
        dfs(0);
        return result;
    }
};

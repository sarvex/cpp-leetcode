/**
 * @brief Check if array can be partitioned into k equal-sum subsets
 * @intuition Backtracking: try assigning each number to one of k buckets
 * @approach Sort descending for early pruning, DFS trying each bucket assignment
 * @complexity Time: O(k^n), Space: O(k + n)
 */
class Solution final {
public:
    [[nodiscard]] static bool canPartitionKSubsets(vector<int>& nums, const int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) {
            return false;
        }
        s /= k;
        
        const int n = nums.size();
        vector<int> cur(k);
        
        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if (i == n) {
                return true;
            }
            for (int j = 0; j < k; ++j) {
                if (j > 0 && cur[j] == cur[j - 1]) {
                    continue;
                }
                cur[j] += nums[i];
                if (cur[j] <= s && dfs(i + 1)) {
                    return true;
                }
                cur[j] -= nums[i];
            }
            return false;
        };
        
        ranges::sort(nums, greater<int>());
        return dfs(0);
    }
};

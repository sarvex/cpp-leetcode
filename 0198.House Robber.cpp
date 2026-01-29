/**
 * @brief Maximum robbery using memoized DP
 * @intuition At each house, choose max of (rob + skip next) or (skip)
 * @approach Top-down DP with memoization, explicit this-lambda recursion
 * @complexity Time: O(n), Space: O(n)
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto rob(vector<int>& nums) const -> int {
        const int n = static_cast<int>(nums.size());
        vector<int> memo(n, -1);
        
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (memo[i] >= 0) {
                return memo[i];
            }
            return memo[i] = std::max(nums[i] + dfs(i + 2), dfs(i + 1));
        };
        
        return dfs(0);
    }
};

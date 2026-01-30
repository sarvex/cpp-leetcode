/**
 * @brief DP to find longest increasing subsequence
 * @intuition f[i] = length of LIS ending at index i
 * @approach For each element, find max LIS length from smaller previous elements
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int lengthOfLIS(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

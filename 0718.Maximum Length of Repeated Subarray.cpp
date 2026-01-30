/**
 * @brief Maximum length of repeated subarray using DP
 * @intuition Similar to longest common substring problem
 * @approach DP where f[i][j] is max length ending at nums1[i-1] and nums2[j-1]
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static int findLength(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        const int m = static_cast<int>(nums1.size());
        const int n = static_cast<int>(nums2.size());
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        int result = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = std::max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};

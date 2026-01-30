/**
 * @brief Interval DP for bursting balloons with maximum coins
 * @intuition Think backwards: which balloon is burst last in each interval
 * @approach DP where f[i][j] = max coins for interval (i,j) with i,j as boundaries
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int maxCoins(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> arr(n + 2, 1);
        
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], 
                                   dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};

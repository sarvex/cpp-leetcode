/**
 * @brief Interval DP for bursting balloons with maximum coins
 * @intuition Think backwards: which balloon is burst last in each interval
 * @approach DP where f[i][j] = max coins for interval (i,j) with i,j as boundaries
 * @complexity Time: O(n^3), Space: O(n^2)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int maxCoins(const std::vector<int>& nums) const {
        const int n = static_cast<int>(nums.size());
        std::vector<int> arr(n + 2, 1);
        
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = nums[i];
        }

        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j], 
                                        dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};

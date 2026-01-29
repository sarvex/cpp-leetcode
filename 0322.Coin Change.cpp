/**
 * @brief DP for minimum coins to make amount
 * @intuition Classic unbounded knapsack problem
 * @approach DP with f[i][j] = min coins using first i coins for amount j
 * @complexity Time: O(m * n), Space: O(m * n)
 */
#include <algorithm>
#include <cstring>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int coinChange(const std::vector<int>& coins, int amount) const {
        const int m = static_cast<int>(coins.size());
        const int n = amount;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0x3f3f3f3f));
        dp[0][0] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        return dp[m][n] > n ? -1 : dp[m][n];
    }
};

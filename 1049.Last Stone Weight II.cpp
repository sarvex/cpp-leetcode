/**
 * @brief Subset sum DP for minimum difference partition
 * @intuition Equivalent to partitioning stones into two groups with minimum difference
 * @approach 0/1 knapsack to find closest sum to half total
 * @complexity Time: O(n * sum), Space: O(n * sum)
 */
class Solution final {
public:
    [[nodiscard]] static int lastStoneWeightII(const vector<int>& stones) {
        const int s = accumulate(stones.begin(), stones.end(), 0);
        const int m = stones.size(), n = s >> 1;
        vector dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (stones[i - 1] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return s - dp[m][n] * 2;
    }
};

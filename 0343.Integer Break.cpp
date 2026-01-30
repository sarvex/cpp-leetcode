/**
 * @brief DP for maximum product by breaking integer
 * @intuition f[i] = max product for integer i, try all splits
 * @approach DP where f[i] = max(f[i-j]*j, (i-j)*j) for all j
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int integerBreak(const int n) {
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = std::max({dp[i], dp[i - j] * j, (i - j) * j});
            }
        }
        return dp[n];
    }
};

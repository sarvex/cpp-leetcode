/**
 * @brief Minimum ASCII delete sum using dynamic programming
 * @intuition Similar to edit distance but track ASCII sum instead of count
 * @approach DP where f[i][j] is min cost to make s1[0..i] and s2[0..j] equal
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static int minimumDeleteSum(const std::string& s1, const std::string& s2) {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

/**
 * @brief Find minimum initial health using backward DP
 * @intuition Work backward from destination; dp[i][j] = min health needed at (i,j)
 * @approach Bottom-right to top-left DP, ensuring health stays positive
 * @complexity Time: O(m*n), Space: O(m*n)
 */

class Solution final {
public:
    [[nodiscard]] static auto calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) -> int {
        const int m = static_cast<int>(dungeon.size());
        const int n = static_cast<int>(dungeon[0].size());
        constexpr int INF = std::numeric_limits<int>::max() / 2;
        
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INF));
        dp[m][n - 1] = dp[m - 1][n] = 1;
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                const int minNext = std::min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = std::max(1, minNext - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};

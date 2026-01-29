/**
 * @brief Find minimum initial health using backward DP
 * @intuition Work backward from destination; dp[i][j] = min health needed at (i,j)
 * @approach Bottom-right to top-left DP, ensuring health stays positive
 * @complexity Time: O(m*n), Space: O(m*n)
 */

#include <algorithm>
#include <limits>
#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto calculateMinimumHP(vector<vector<int>>& dungeon) const -> int {
        const int m = static_cast<int>(dungeon.size());
        const int n = static_cast<int>(dungeon[0].size());
        constexpr int INF = std::numeric_limits<int>::max() / 2;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
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

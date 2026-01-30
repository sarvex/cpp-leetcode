/**
 * @brief Cherry pickup with two paths using 3D DP
 * @intuition Simulate two people walking simultaneously to avoid recounting
 * @approach DP with state (step, row1, row2) representing two paths at same step
 * @complexity Time: O(n^3), Space: O(n^3)
 */
class Solution final {
public:
    [[nodiscard]] static int cherryPickup(const std::vector<std::vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        std::vector<std::vector<std::vector<int>>> dp(
            n << 1, std::vector<std::vector<int>>(n, std::vector<int>(n, -1e9)));
        dp[0][0][0] = grid[0][0];
        
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 < n; ++i2) {
                    const int j1 = k - i1;
                    const int j2 = k - i2;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || 
                        grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        continue;
                    }
                    int cherries = grid[i1][j1];
                    if (i1 != i2) {
                        cherries += grid[i2][j2];
                    }
                    for (int x1 = i1 - 1; x1 <= i1; ++x1) {
                        for (int x2 = i2 - 1; x2 <= i2; ++x2) {
                            if (x1 >= 0 && x2 >= 0) {
                                dp[k][i1][i2] = std::max(dp[k][i1][i2], dp[k - 1][x1][x2] + cherries);
                            }
                        }
                    }
                }
            }
        }
        return std::max(0, dp[n * 2 - 2][n - 1][n - 1]);
    }
};

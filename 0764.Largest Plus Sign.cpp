/**
 * @brief Find largest plus sign in grid with mines
 * @intuition For each cell, find min arm length in all 4 directions
 * @approach DP: compute arm lengths from all directions, take minimum
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int orderOfLargestPlusSign(const int n, 
                                                     const std::vector<std::vector<int>>& mines) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, n));
        for (const auto& mine : mines) {
            dp[mine[0]][mine[1]] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0, up = 0, down = 0;
            for (int j = 0, k = n - 1; j < n; ++j, --k) {
                left = dp[i][j] ? left + 1 : 0;
                right = dp[i][k] ? right + 1 : 0;
                up = dp[j][i] ? up + 1 : 0;
                down = dp[k][i] ? down + 1 : 0;
                dp[i][j] = std::min(dp[i][j], left);
                dp[i][k] = std::min(dp[i][k], right);
                dp[j][i] = std::min(dp[j][i], up);
                dp[k][i] = std::min(dp[k][i], down);
            }
        }
        
        int result = 0;
        for (const auto& row : dp) {
            result = std::max(result, *std::ranges::max_element(row));
        }
        return result;
    }
};

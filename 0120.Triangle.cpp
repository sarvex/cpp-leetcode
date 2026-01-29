/**
 * @brief Find minimum path sum in triangle using bottom-up DP
 * @intuition Work from bottom, each cell becomes min of two below plus itself
 * @approach 1D DP array updated from bottom row to top
 * @complexity Time: O(n^2), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto minimumTotal(const std::vector<std::vector<int>>& triangle) -> int {
        const int n = static_cast<int>(triangle.size());
        std::vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};

/**
 * @brief Count structurally unique BSTs using Catalan numbers
 * @intuition For root i, count = left subtree count * right subtree count
 * @approach DP computing Catalan numbers: f[i] = sum of f[j] * f[i-j-1] for all j
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto numTrees(const int n) -> int {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
};

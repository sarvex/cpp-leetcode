/**
 * @brief Minimum deletions to make two strings equal (edit distance variant)
 * @intuition Result = len1 + len2 - 2*LCS, or use DP directly for min deletions
 * @approach DP where f[i][j] = min deletions for word1[0..i) and word2[0..j)
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static int minDistance(const string& word1, const string& word2) {
        const int m = static_cast<int>(word1.length());
        const int n = static_cast<int>(word2.length());
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};

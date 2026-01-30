/**
 * @brief Classic DP for longest common subsequence
 * @intuition Build solution by comparing characters and taking max of excluding either
 * @approach Use 2D DP where f[i][j] is LCS of first i chars of text1 and first j chars of text2.
 *           If chars match, extend from f[i-1][j-1]. Otherwise, take max of f[i-1][j] or f[i][j-1].
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static int longestCommonSubsequence(const string& text1, const string& text2) {
        const int m = text1.size(), n = text2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
};

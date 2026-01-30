/**
 * @brief Longest Common Subsequence (LCS) problem
 * @intuition Non-crossing lines form an increasing subsequence; equivalent to LCS
 * @approach Classic DP: f[i][j] = LCS of nums1[0..i] and nums2[0..j]
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxUncrossedLines(const vector<int>& nums1, const vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
};

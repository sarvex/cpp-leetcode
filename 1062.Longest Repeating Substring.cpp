/**
 * @brief DP for longest repeating substring
 * @intuition f[i][j] = length of common suffix ending at i and j (i > j)
 * @approach Compare all pairs of positions, track maximum matching length
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int longestRepeatingSubstring(const string& s) {
        const int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = 1 + (j > 0 ? f[i - 1][j - 1] : 0);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};

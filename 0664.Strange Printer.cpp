/**
 * @brief Minimum turns for strange printer to print string
 * @intuition DP on intervals; if endpoints match, can print together
 * @approach f[i][j] = min turns for substring [i,j], optimize when s[i] == s[j]
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int strangePrinter(const string& s) {
        const int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MAX));
        
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};

/**
 * @brief Dynamic programming for longest palindromic subsequence
 * @intuition Build solution from smaller substrings; matching endpoints extend palindrome by 2
 * @approach DP where f[i][j] = LPS length for s[i..j]. If s[i]==s[j], f[i][j] = f[i+1][j-1]+2.
 *           Otherwise take max of f[i+1][j] and f[i][j-1]. Process in reverse order of i.
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto longestPalindromeSubseq(const string& s) -> int {
        const int n = static_cast<int>(s.size());
        vector<vector<int>> f(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return f[0][n - 1];
    }
};

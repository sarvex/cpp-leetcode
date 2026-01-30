/**
 * @brief Count distinct palindromic subsequences
 * @intuition DP with character-specific counting to handle duplicates
 * @approach dp[i][j][c] = count of palindromes starting and ending with char c in s[i..j]
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int countPalindromicSubsequences(const std::string& s) {
        constexpr int MOD = 1e9 + 7;
        const int n = static_cast<int>(s.size());
        std::vector<std::vector<std::array<long long, 4>>> dp(
            n, std::vector<std::array<long long, 4>>(n, {0, 0, 0, 0}));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i][s[i] - 'a'] = 1;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                const int j = i + len - 1;
                for (int c = 0; c < 4; ++c) {
                    const char ch = 'a' + c;
                    if (s[i] == ch && s[j] == ch) {
                        long long sum = 0;
                        for (int k = 0; k < 4; ++k) {
                            sum += dp[i + 1][j - 1][k];
                        }
                        dp[i][j][c] = (2 + sum) % MOD;
                    } else if (s[i] == ch) {
                        dp[i][j][c] = dp[i][j - 1][c];
                    } else if (s[j] == ch) {
                        dp[i][j][c] = dp[i + 1][j][c];
                    } else {
                        dp[i][j][c] = dp[i + 1][j - 1][c];
                    }
                }
            }
        }
        
        long long result = 0;
        for (int c = 0; c < 4; ++c) {
            result += dp[0][n - 1][c];
        }
        return static_cast<int>(result % MOD);
    }
};

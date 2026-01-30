/**
 * @brief Minimum window subsequence using DP
 * @intuition Track starting position of valid subsequence ending at each position
 * @approach DP where f[i][j] is start index of subsequence s2[0..j] in s1[0..i]
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static std::string minWindow(const std::string& s1, const std::string& s2) {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = (j == 1) ? i : dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        int start = 0;
        int minLen = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s2[n - 1] && dp[i][n]) {
                const int begin = dp[i][n] - 1;
                if (i - begin < minLen) {
                    minLen = i - begin;
                    start = begin;
                }
            }
        }
        return minLen > m ? "" : s1.substr(start, minLen);
    }
};

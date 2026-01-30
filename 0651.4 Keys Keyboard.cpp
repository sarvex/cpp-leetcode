/**
 * @brief Maximum A's printable in n keystrokes using A, Ctrl-A, Ctrl-C, Ctrl-V
 * @intuition DP: at each step, either type A or do copy-paste sequence
 * @approach dp[i] = max A's with i keystrokes, try all copy-paste combinations
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxA(const int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 2; j < i - 1; ++j) {
                dp[i] = max(dp[i], dp[j - 1] * (i - j));
            }
        }
        return dp[n];
    }
};

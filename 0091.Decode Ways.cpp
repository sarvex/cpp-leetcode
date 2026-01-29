/**
 * @brief Dynamic programming to count valid letter decodings
 * @intuition Each digit can be decoded alone (1-9) or as part of two-digit (10-26)
 * @approach DP where f[i] = ways to decode first i characters; check valid single/double digits
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto numDecodings(const string& s) -> int {
        const int n = static_cast<int>(s.size());
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};

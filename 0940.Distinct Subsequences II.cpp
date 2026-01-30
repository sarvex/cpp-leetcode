/**
 * @brief Count distinct subsequences using DP
 * @intuition Each character extends all previous subsequences, track by last char
 * @approach For each char, new count = sum of all previous + 1, stored by char
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int distinctSubseqII(const string& s) {
        constexpr int mod = 1e9 + 7;
        vector<long> dp(26);
        for (const char c : s) {
            const int i = c - 'a';
            dp[i] = accumulate(dp.begin(), dp.end(), 1L) % mod;
        }
        return static_cast<int>(accumulate(dp.begin(), dp.end(), 0L) % mod);
    }
};

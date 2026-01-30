/**
 * @brief Count ways to tile 2×n board with dominoes and trominoes
 * @intuition Track 4 states: both filled, top only, bottom only, neither
 * @approach DP with state transitions for each column configuration
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int numTilings(const int n) {
        constexpr int MOD = 1e9 + 7;
        std::array<long long, 4> dp{1, 0, 0, 0};
        
        for (int i = 1; i <= n; ++i) {
            std::array<long long, 4> next{0, 0, 0, 0};
            next[0] = (dp[0] + dp[1] + dp[2] + dp[3]) % MOD;
            next[1] = (dp[2] + dp[3]) % MOD;
            next[2] = (dp[1] + dp[3]) % MOD;
            next[3] = dp[0];
            dp = next;
        }
        return static_cast<int>(dp[0]);
    }
};

/**
 * @brief Count derangements (permutations with no fixed points) of n elements
 * @intuition Use recurrence: D(n) = (n-1) * (D(n-1) + D(n-2))
 * @approach DP with space optimization, computing derangement count iteratively
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findDerangement(const int n) {
        if (n < 2) {
            return 0;
        }
        
        vector<long long> f(n + 1);
        f[0] = 1;
        constexpr int mod = 1e9 + 7;
        
        for (int i = 2; i <= n; ++i) {
            f[i] = (i - 1LL) * (f[i - 1] + f[i - 2]) % mod;
        }
        return f[n];
    }
};

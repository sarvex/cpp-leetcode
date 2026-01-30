/**
 * @brief Count arrays of 1 to n with exactly k inverse pairs
 * @intuition DP with prefix sums to optimize counting valid permutations
 * @approach f[j] = number of arrays with j inverse pairs, use prefix sums for efficiency
 * @complexity Time: O(n * k), Space: O(k)
 */
class Solution final {
public:
    [[nodiscard]] static int kInversePairs(const int n, const int k) {
        vector<int> f(k + 1);
        vector<int> s(k + 2, 1);
        f[0] = 1;
        s[0] = 0;
        
        constexpr int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[j] = (s[j + 1] - s[max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                s[j] = (s[j - 1] + f[j - 1]) % mod;
            }
        }
        return f[k];
    }
};

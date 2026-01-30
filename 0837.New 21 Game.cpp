/**
 * @brief Memoized recursion with sliding window for probability calculation
 * @intuition Use DP where probability at state i depends on next maxPts states
 * @approach Define f[i] as probability of reaching <= n starting from score i.
 *           Use recurrence: f[i] = f[i+1] + (f[i+1] - f[i+maxPts+1]) / maxPts.
 * @complexity Time: O(k), Space: O(k)
 */
class Solution final {
public:
    [[nodiscard]] static auto new21Game(int n, int k, int maxPts) -> double {
        std::vector<double> f(k);
        
        auto dfs = [&](auto&& self, int i) -> double {
            if (i >= k) {
                return i <= n ? 1.0 : 0.0;
            }
            if (i == k - 1) {
                return std::min(n - k + 1, maxPts) * 1.0 / maxPts;
            }
            if (f[i] > 0) {
                return f[i];
            }
            return f[i] = self(self, i + 1) + 
                         (self(self, i + 1) - self(self, i + maxPts + 1)) / maxPts;
        };
        
        return dfs(dfs, 0);
    }
};

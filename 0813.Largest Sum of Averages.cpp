/**
 * @brief Memoized recursion for partitioning array to maximize sum of averages
 * @intuition Use DP to track best partition at each position with remaining groups
 * @approach For each position, try all possible partition points. Recursively compute
 *           maximum sum of averages using prefix sums for efficient average calculation.
 * @complexity Time: O(n^2 * k), Space: O(n * k)
 */
class Solution final {
public:
    [[nodiscard]] static auto largestSumOfAverages(const std::vector<int>& nums,
                                                    int k) -> double {
        const int n = static_cast<int>(nums.size());
        std::vector<int> s(n + 1);
        std::vector<std::vector<double>> f(n, std::vector<double>(k + 1, 0.0));
        
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        
        auto dfs = [&](auto&& self, int i, int remaining) -> double {
            if (i == n) return 0.0;
            if (remaining == 1) {
                return static_cast<double>(s[n] - s[i]) / (n - i);
            }
            if (f[i][remaining] > 0) {
                return f[i][remaining];
            }
            
            double ans = 0.0;
            for (int j = i + 1; j < n; ++j) {
                const double avg = static_cast<double>(s[j] - s[i]) / (j - i);
                ans = std::max(ans, avg + self(self, j, remaining - 1));
            }
            return f[i][remaining] = ans;
        };
        
        return dfs(dfs, 0, k);
    }
};

/**
 * @brief 3D DP counting schemes achieving minimum profit with limited members
 * @intuition For each crime, decide include or not; track members used and profit
 * @approach f[i][j][k] = ways using first i crimes, j members, achieving k profit.
 *           For each crime, either skip or include (if enough members remain).
 * @complexity Time: O(m * n * minProfit), Space: O(m * n * minProfit)
 */
class Solution final {
public:
    [[nodiscard]] static auto profitableSchemes(int n, int minProfit,
        const std::vector<int>& group,
        const std::vector<int>& profit) -> int {
        const int m = static_cast<int>(group.size());
        constexpr int mod = 1'000'000'007;
        std::vector<std::vector<std::vector<int>>> f(
            m, std::vector<std::vector<int>>(n + 1, std::vector<int>(minProfit + 1, -1)));
        
        auto dfs = [&](auto&& self, int i, int j, int k) -> int {
            if (i >= m) {
                return k == minProfit ? 1 : 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = self(self, i + 1, j, k);
            if (j + group[i] <= n) {
                ans += self(self, i + 1, j + group[i], 
                           std::min(k + profit[i], minProfit));
                ans %= mod;
            }
            return f[i][j][k] = ans;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};

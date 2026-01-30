/**
 * @brief Count combinations to make amount using unbounded coins
 * @intuition Classic unbounded knapsack; each coin can be used unlimited times
 * @approach DP where f[i][j] = ways to make amount j using first i coin types.
 *           f[i][j] = f[i-1][j] (skip coin) + f[i][j-coin] (use coin again).
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static auto change(int amount, const vector<int>& coins) -> int {
        const int m = static_cast<int>(coins.size());
        const int n = amount;
        vector<vector<unsigned>> f(m + 1, vector<unsigned>(n + 1, 0));
        f[0][0] = 1;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1]) {
                    f[i][j] += f[i][j - coins[i - 1]];
                }
            }
        }
        return static_cast<int>(f[m][n]);
    }
};

/**
 * @brief Minimax with memoization to maximize Alice's stones
 * @intuition Each player takes 1 to 2M piles optimally; track remaining stones via suffix sums
 * @approach Use DP where f[i][m] is max stones from position i with parameter m. Player takes
 *           1 to 2m piles, opponent plays optimally on remainder. Maximize (total - opponent's best).
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int stoneGameII(const vector<int>& piles) {
        const int n = piles.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + piles[i];
        }
        vector<vector<int>> f(n, vector<int>(n + 1, 0));
        auto dfs = [&](this auto&& dfs, int i, int m) -> int {
            if (m * 2 >= n - i) {
                return s[n] - s[i];
            }
            if (f[i][m]) {
                return f[i][m];
            }
            int res = 0;
            for (int x = 1; x <= m << 1; ++x) {
                res = max(res, s[n] - s[i] - dfs(i + x, max(x, m)));
            }
            return f[i][m] = res;
        };
        return dfs(0, 1);
    }
};

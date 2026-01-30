/**
 * @brief Memoized recursion to build tree with minimum sum of non-leaf node values
 * @intuition Each non-leaf node's value is product of max values in its left and right subtrees
 * @approach Precompute max values for all ranges. Use interval DP where we try all possible
 *           split points and find minimum total cost recursively.
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int mctFromLeafValues(const vector<int>& arr) {
        const int n = arr.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = max(g[i][j - 1], arr[j]);
            }
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i == j) {
                return 0;
            }
            if (f[i][j] > 0) {
                return f[i][j];
            }
            int ans = 1 << 30;
            for (int k = i; k < j; ++k) {
                ans = min(ans, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};

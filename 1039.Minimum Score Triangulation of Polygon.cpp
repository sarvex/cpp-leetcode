/**
 * @brief Interval DP for polygon triangulation
 * @intuition Split polygon at each vertex, minimize sum of triangle products
 * @approach f[i][j] = min cost to triangulate polygon from vertex i to j
 * @complexity Time: O(n^3), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int minScoreTriangulation(const vector<int>& values) {
        const int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        function<int(int, int)> dfs = [&](const int i, const int j) -> int {
            if (i + 1 == j) {
                return 0;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            int ans = 1 << 30;
            for (int k = i + 1; k < j; ++k) {
                ans = min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};

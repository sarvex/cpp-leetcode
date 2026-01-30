/**
 * @brief Count paths that exit grid within maxMove steps using memoized DFS
 * @intuition State: current position and remaining moves; count exits in 4 directions
 * @approach DFS with memo[i][j][k] = paths from (i,j) with k moves remaining
 * @complexity Time: O(m*n*maxMove), Space: O(m*n*maxMove)
 */
class Solution final {
public:
    [[nodiscard]] static int findPaths(const int m, const int n, const int maxMove,
                                        const int startRow, const int startColumn) {
        int memo[m][n][maxMove + 1];
        memset(memo, -1, sizeof(memo));
        constexpr int mod = 1e9 + 7;
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return k >= 0 ? 1 : 0;
            }
            if (k <= 0) {
                return 0;
            }
            if (memo[i][j][k] != -1) {
                return memo[i][j][k];
            }
            
            int ans = 0;
            for (int d = 0; d < 4; ++d) {
                const int x = i + dirs[d];
                const int y = j + dirs[d + 1];
                ans = (ans + dfs(x, y, k - 1)) % mod;
            }
            
            return memo[i][j][k] = ans;
        };
        
        return dfs(startRow, startColumn, maxMove);
    }
};

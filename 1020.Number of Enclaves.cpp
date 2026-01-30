/**
 * @brief DFS flood fill from borders to eliminate non-enclaves
 * @intuition Cells connected to border are not enclaves; flood fill from edges
 * @approach DFS from border cells marking them as 0, then count remaining 1s
 * @complexity Time: O(m * n), Space: O(m * n) for recursion stack
 */
class Solution final {
public:
    [[nodiscard]] static int numEnclaves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](const int i, const int j) {
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    dfs(x, y);
                }
            }
        };
        for (int j = 0; j < n; ++j) {
            for (const int i : {0, m - 1}) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (const int j : {0, n - 1}) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        int ans = 0;
        for (const auto& row : grid) {
            ans += accumulate(row.begin(), row.end(), 0);
        }
        return ans;
    }
};

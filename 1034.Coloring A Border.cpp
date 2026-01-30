/**
 * @brief DFS marking border cells of connected component
 * @intuition Border cells have neighbor outside component or at grid edge
 * @approach DFS to find component, mark border cells during traversal
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> colorBorder(
        vector<vector<int>>& grid, const int row, const int col, const int color) {
        const int m = grid.size();
        const int n = grid[0].size();
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int, int)> dfs = [&](const int i, const int j, const int c) {
            vis[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (!vis[x][y]) {
                        if (grid[x][y] == c) {
                            dfs(x, y, c);
                        } else {
                            grid[i][j] = color;
                        }
                    }
                } else {
                    grid[i][j] = color;
                }
            }
        };
        dfs(row, col, grid[row][col]);
        return grid;
    }
};

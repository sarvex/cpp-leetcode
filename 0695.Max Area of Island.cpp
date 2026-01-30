/**
 * @brief Find maximum area island in grid
 * @intuition DFS from each land cell, count connected cells
 * @approach Mark visited by setting to 0, recursively count neighbors
 * @complexity Time: O(m * n), Space: O(m * n) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        int ans = 0;
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (grid[i][j] == 0) {
                return 0;
            }
            int area = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    area += dfs(x, y);
                }
            }
            return area;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};

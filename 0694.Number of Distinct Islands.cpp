/**
 * @brief Count distinct island shapes using path signature
 * @intuition Encode DFS path as string to identify unique shapes
 * @approach DFS marking visited cells, record direction sequence as signature
 * @complexity Time: O(m * n), Space: O(m * n)
 */
class Solution final {
public:
    [[nodiscard]] static int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> paths;
        string path;
        const int m = grid.size();
        const int n = grid[0].size();
        constexpr int dirs[] = {-1, 0, 1, 0, -1};
        
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> void {
            grid[i][j] = 0;
            path += to_string(k);
            for (int h = 1; h < 5; ++h) {
                const int x = i + dirs[h - 1];
                const int y = j + dirs[h];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                    dfs(x, y, h);
                }
            }
            path += to_string(k);
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j, 0);
                    paths.insert(path);
                    path.clear();
                }
            }
        }
        return paths.size();
    }
};

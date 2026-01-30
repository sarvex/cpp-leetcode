/**
 * @brief BFS from one island to find shortest bridge to another
 * @intuition DFS to mark first island, BFS to expand until reaching second
 * @approach Mark first island with DFS, add boundary to queue, BFS expand
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int shortestBridge(vector<vector<int>>& grid) {
        static constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        const int n = static_cast<int>(grid.size());
        queue<pair<int, int>> q;
        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            grid[i][j] = 2;
            q.emplace(i, j);
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                    dfs(x, y);
                }
            }
        };
        for (int i = 0, found = 0; i < n && !found; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j);
                    found = 1;
                    break;
                }
            }
        }
        int ans = 0;
        while (true) {
            for (int h = static_cast<int>(q.size()); h > 0; --h) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    const int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1) return ans;
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            q.emplace(x, y);
                        }
                    }
                }
            }
            ++ans;
        }
    }
};

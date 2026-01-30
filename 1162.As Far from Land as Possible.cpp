/**
 * @brief Multi-source BFS from all land cells to find maximum distance to any water cell
 * @intuition Start BFS from all land cells simultaneously; last reached water cell is farthest
 * @approach Queue all land cells initially. Expand BFS to unvisited water cells level by level.
 *           Track distance; return final distance when all reachable cells are visited.
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                }
            }
        }
        int ans = -1;
        if (q.empty() || q.size() == n * n) {
            return ans;
        }
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int m = q.size(); m; --m) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                        grid[x][y] = 1;
                        q.emplace(x, y);
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
};

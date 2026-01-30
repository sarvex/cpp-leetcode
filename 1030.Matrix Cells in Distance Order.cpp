/**
 * @brief BFS from center cell to sort by Manhattan distance
 * @intuition BFS naturally explores cells in order of distance from source
 * @approach Start BFS from center, collect cells in visit order
 * @complexity Time: O(rows * cols), Space: O(rows * cols)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> allCellsDistOrder(
        const int rows, const int cols, const int rCenter, const int cCenter) {
        queue<pair<int, int>> q;
        q.emplace(rCenter, cCenter);
        vector<vector<int>> ans;
        bool vis[rows][cols];
        memset(vis, false, sizeof(vis));
        vis[rCenter][cCenter] = true;
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto [i, j] = q.front();
                q.pop();
                ans.push_back({i, j});
                for (int k = 0; k < 4; ++k) {
                    const int x = i + dirs[k];
                    const int y = j + dirs[k + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y]) {
                        vis[x][y] = true;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return ans;
    }
};

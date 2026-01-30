/**
 * @brief Union-Find with sorted cells to find path maximizing minimum value
 * @intuition Process cells in descending order of value and use union-find to connect adjacent visited cells
 * @approach Sort all cells by value in descending order. Process cells one by one, marking them as visited
 *           and unioning with adjacent visited cells. The answer is the value when top-left connects to bottom-right.
 * @complexity Time: O(m*n * log(m*n) * alpha(m*n)), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static int maximumMinimumPath(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<tuple<int, int, int>> q;
        vector<int> p(m * n);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace_back(grid[i][j], i, j);
            }
        }
        auto find = [&](this auto&& find, int x) -> int {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        ranges::sort(q, greater<tuple<int, int, int>>());
        int ans = 0;
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (auto& [v, i, j] : q) {
            vis[i][j] = true;
            ans = v;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y]) {
                    p[find(x * n + y)] = find(i * n + j);
                }
            }
            if (find(0) == find(m * n - 1)) {
                break;
            }
        }
        return ans;
    }
};

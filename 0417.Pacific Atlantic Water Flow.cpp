/**
 * @brief Find cells where water can flow to both Pacific and Atlantic oceans
 * @intuition BFS from ocean borders inward, find intersection of reachable cells
 * @approach Two BFS from each ocean edge, return cells in both visited sets
 * @complexity Time: O(m*n), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] static auto pacificAtlantic(std::vector<std::vector<int>>& heights)
        -> std::vector<std::vector<int>> {
        const auto m = static_cast<int>(heights.size());
        const auto n = static_cast<int>(heights[0].size());

        std::queue<std::pair<int, int>> q1;
        std::queue<std::pair<int, int>> q2;
        std::unordered_set<int> vis1;
        std::unordered_set<int> vis2;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    vis1.insert(i * n + j);
                    q1.emplace(i, j);
                }
                if (i == m - 1 || j == n - 1) {
                    vis2.insert(i * n + j);
                    q2.emplace(i, j);
                }
            }
        }

        auto bfs = [&](std::queue<std::pair<int, int>>& q, std::unordered_set<int>& vis) {
            constexpr int dirs[5] = {-1, 0, 1, 0, -1};
            while (!q.empty()) {
                auto [pi, pj] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    const int x = pi + dirs[d];
                    const int y = pj + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        !vis.contains(x * n + y) && heights[x][y] >= heights[pi][pj]) {
                        vis.insert(x * n + y);
                        q.emplace(x, y);
                    }
                }
            }
        };

        bfs(q1, vis1);
        bfs(q2, vis2);

        std::vector<std::vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const int x = i * n + j;
                if (vis1.contains(x) && vis2.contains(x)) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

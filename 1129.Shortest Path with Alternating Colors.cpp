/**
 * @brief BFS to find shortest paths with alternating red/blue edges
 * @intuition Track state as (node, last_color) and use BFS for shortest paths
 * @approach Build separate graphs for red and blue edges. BFS from node 0 with both colors.
 *           At each step, only follow edges of the opposite color. Track visited states.
 * @complexity Time: O(n + E), Space: O(n + E) where E is total edges
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> shortestAlternatingPaths(const int n,
                                                              const vector<vector<int>>& redEdges,
                                                              const vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
        for (const auto& e : redEdges) {
            g[0][e[0]].push_back(e[1]);
        }
        for (const auto& e : blueEdges) {
            g[1][e[0]].push_back(e[1]);
        }
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(0, 1);
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vector<int> ans(n, -1);
        int d = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto [i, c] = q.front();
                q.pop();
                if (ans[i] == -1) {
                    ans[i] = d;
                }
                vis[i][c] = true;
                int nc = c ^ 1;
                for (int j : g[nc][i]) {
                    if (!vis[j][nc]) {
                        q.emplace(j, nc);
                    }
                }
            }
            ++d;
        }
        return ans;
    }
};

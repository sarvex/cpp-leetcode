/**
 * @brief DFS with cycle detection and destination verification
 * @intuition All paths must reach destination; detect cycles and dead ends
 * @approach DFS with visited tracking for cycles, memoization for results
 * @complexity Time: O(V + E), Space: O(V + E)
 */
class Solution final {
public:
    [[nodiscard]] static bool leadsToDestination(
        const int n,
        const vector<vector<int>>& edges,
        const int source,
        const int destination) {
        
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        vector<int> f(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        function<bool(int)> dfs = [&](const int i) {
            if (i == destination) {
                return g[i].empty();
            }
            if (f[i]) {
                return f[i] == 1;
            }
            if (vis[i] || g[i].empty()) {
                return false;
            }
            vis[i] = true;
            for (const int j : g[i]) {
                if (!dfs(j)) {
                    f[i] = -1;
                    return false;
                }
            }
            f[i] = 1;
            return true;
        };
        return dfs(source);
    }
};

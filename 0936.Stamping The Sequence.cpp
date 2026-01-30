/**
 * @brief Reverse simulation of stamping process using topological sort
 * @intuition Work backwards from target; positions become stampable as chars match
 * @approach Build dependency graph, process nodes with zero in-degree first
 * @complexity Time: O(n * m), Space: O(n * m)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> movesToStamp(const string& stamp, const string& target) {
        const int m = static_cast<int>(stamp.size()), n = static_cast<int>(target.size());
        vector<int> indeg(n - m + 1, m);
        vector<int> g[n];
        queue<int> q;
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    if (--indeg[i] == 0) {
                        q.push(i);
                    }
                } else {
                    g[i + j].push_back(i);
                }
            }
        }
        vector<int> ans;
        vector<bool> vis(n);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            ans.push_back(i);
            for (int j = 0; j < m; ++j) {
                if (!vis[i + j]) {
                    vis[i + j] = true;
                    for (const int k : g[i + j]) {
                        if (--indeg[k] == 0) {
                            q.push(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return {};
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};

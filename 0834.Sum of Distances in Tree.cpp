/**
 * @brief Two DFS passes to compute sum of distances for all nodes
 * @intuition Rerooting technique: use relationship between parent and child answers
 * @approach First DFS: compute answer for root and subtree sizes. Second DFS:
 *           for child j of node i: ans[j] = ans[i] - size[j] + (n - size[j]).
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto sumOfDistancesInTree(int n,
        const std::vector<std::vector<int>>& edges) -> std::vector<int> {
        std::vector<std::vector<int>> g(n);
        for (const auto& e : edges) {
            const int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        std::vector<int> ans(n);
        std::vector<int> sz(n);
        
        auto dfs1 = [&](auto&& self, int i, int fa, int d) -> void {
            ans[0] += d;
            sz[i] = 1;
            for (const int j : g[i]) {
                if (j != fa) {
                    self(self, j, i, d + 1);
                    sz[i] += sz[j];
                }
            }
        };
        
        auto dfs2 = [&](auto&& self, int i, int fa, int t) -> void {
            ans[i] = t;
            for (const int j : g[i]) {
                if (j != fa) {
                    self(self, j, i, t - sz[j] + n - sz[j]);
                }
            }
        };
        
        dfs1(dfs1, 0, -1, 0);
        dfs2(dfs2, 0, -1, ans[0]);
        return ans;
    }
};

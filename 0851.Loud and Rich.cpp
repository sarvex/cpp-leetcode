/**
 * @brief DFS with memoization to find quietest person among richer set
 * @intuition Build directed graph from richer to poorer; DFS finds quietest ancestor
 * @approach For each person, recursively find the quietest person among all who are
 *           richer. Memoize results to avoid recomputation.
 * @complexity Time: O(n + e), Space: O(n + e)
 */
class Solution final {
public:
    [[nodiscard]] static auto loudAndRich(
        const std::vector<std::vector<int>>& richer,
        const std::vector<int>& quiet) -> std::vector<int> {
        const int n = static_cast<int>(quiet.size());
        std::vector<std::vector<int>> g(n);
        
        for (const auto& r : richer) {
            g[r[1]].push_back(r[0]);
        }
        
        std::vector<int> ans(n, -1);
        
        auto dfs = [&](auto&& self, int i) -> void {
            if (ans[i] != -1) return;
            ans[i] = i;
            for (const int j : g[i]) {
                self(self, j);
                if (quiet[ans[j]] < quiet[ans[i]]) {
                    ans[i] = ans[j];
                }
            }
        };
        
        for (int i = 0; i < n; ++i) {
            dfs(dfs, i);
        }
        return ans;
    }
};

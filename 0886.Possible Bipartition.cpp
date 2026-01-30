/**
 * @brief Graph coloring to check if bipartition is possible
 * @intuition Bipartition exists iff graph is 2-colorable (no odd cycles)
 * @approach Build graph from dislikes. DFS to 2-color: if neighbors have same color,
 *           bipartition is impossible. Check all connected components.
 * @complexity Time: O(n + e), Space: O(n + e)
 */
class Solution final {
public:
    [[nodiscard]] static auto possibleBipartition(int n,
        const std::vector<std::vector<int>>& dislikes) -> bool {
        std::vector<std::vector<int>> g(n);
        
        for (const auto& e : dislikes) {
            const int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        std::vector<int> color(n, 0);
        
        auto dfs = [&](auto&& self, int i, int c) -> bool {
            color[i] = c;
            for (const int j : g[i]) {
                if (color[j] == 0 && !self(self, j, 3 - c)) return false;
                if (color[j] == c) return false;
            }
            return true;
        };
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(dfs, i, 1)) {
                return false;
            }
        }
        return true;
    }
};

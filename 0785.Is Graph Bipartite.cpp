/**
 * @brief Check if graph is bipartite using DFS coloring
 * @intuition Bipartite iff no odd-length cycles; 2-color graph without conflicts
 * @approach DFS with alternating colors; conflict means not bipartite
 * @complexity Time: O(V + E), Space: O(V)
 */
class Solution final {
public:
    [[nodiscard]] static bool isBipartite(const std::vector<std::vector<int>>& graph) {
        const int n = static_cast<int>(graph.size());
        std::vector<int> color(n, 0);
        
        auto dfs = [&](auto&& self, int node, int c) -> bool {
            color[node] = c;
            for (const int neighbor : graph[node]) {
                if (color[neighbor] == c || 
                    (color[neighbor] == 0 && !self(self, neighbor, -c))) {
                    return false;
                }
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

/**
 * @brief Reverse graph with topological sort to find safe nodes
 * @intuition A node is safe if all paths from it lead to terminal nodes (no cycles)
 * @approach Build reverse graph and perform topological sort. Start from terminal nodes
 *           (out-degree 0) and work backwards. Nodes that can be reached this way are safe.
 * @complexity Time: O(V + E), Space: O(V + E)
 */
class Solution final {
public:
    [[nodiscard]] static auto eventualSafeNodes(
        const std::vector<std::vector<int>>& graph) -> std::vector<int> {
        const int n = static_cast<int>(graph.size());
        std::vector<int> indeg(n);
        std::vector<std::vector<int>> rg(n);
        std::queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            for (const int j : graph[i]) {
                rg[j].push_back(i);
            }
            indeg[i] = static_cast<int>(graph[i].size());
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            for (const int j : rg[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        
        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

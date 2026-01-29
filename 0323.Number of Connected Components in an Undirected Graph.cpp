/**
 * @brief DFS to count connected components in undirected graph
 * @intuition Each DFS from unvisited node discovers one component
 * @approach Mark visited nodes during DFS, count starting points
 * @complexity Time: O(V + E), Space: O(V + E)
 */
#include <functional>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int countComponents(int n, std::vector<std::vector<int>>& edges) const {
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        std::vector<bool> visited(n);
        std::function<int(int)> dfs = [&](int node) -> int {
            if (visited[node]) {
                return 0;
            }
            visited[node] = true;
            for (const int neighbor : graph[node]) {
                dfs(neighbor);
            }
            return 1;
        };
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i);
        }
        return ans;
    }
};

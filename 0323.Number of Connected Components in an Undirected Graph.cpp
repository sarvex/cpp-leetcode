/**
 * @brief DFS to count connected components in undirected graph
 * @intuition Each DFS from unvisited node discovers one component
 * @approach Mark visited nodes during DFS, count starting points
 * @complexity Time: O(V + E), Space: O(V + E)
 */
class Solution final {
public:
    [[nodiscard]] static int countComponents(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> visited(n);
        function<void(int)> dfs = [&](int node) {
            if (visited[node]) {
                return;
            }
            visited[node] = true;
            for (const int neighbor : graph[node]) {
                dfs(neighbor);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans;
    }
};

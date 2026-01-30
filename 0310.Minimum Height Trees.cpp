/**
 * @brief Topological sort to find minimum height tree roots
 * @intuition MHT roots are the centers of the tree - at most 2 nodes
 * @approach BFS from leaves, peeling layer by layer until 1-2 nodes remain
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> findMinHeightTrees(int n, 
                                                         const vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        
        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            const int size = static_cast<int>(q.size());
            for (int i = 0; i < size; ++i) {
                const int node = q.front();
                q.pop();
                ans.push_back(node);
                for (const int neighbor : graph[node]) {
                    if (--degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return ans;
    }
};

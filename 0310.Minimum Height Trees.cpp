/**
 * @brief Topological sort to find minimum height tree roots
 * @intuition MHT roots are the centers of the tree - at most 2 nodes
 * @approach BFS from leaves, peeling layer by layer until 1-2 nodes remain
 * @complexity Time: O(n), Space: O(n)
 */
#include <queue>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<int> findMinHeightTrees(int n, 
                                                       std::vector<std::vector<int>>& edges) const {
        if (n == 1) {
            return {0};
        }
        
        std::vector<std::vector<int>> graph(n);
        std::vector<int> degree(n);
        
        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        std::vector<int> ans;
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

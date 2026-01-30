/**
 * @brief BFS with bitmask state for shortest path visiting all nodes
 * @intuition State = (current node, set of visited nodes); BFS finds shortest path
 * @approach Use BFS where state is (node, visited bitmask). Start from all nodes
 *           (any can be starting point). Goal is when bitmask has all bits set.
 * @complexity Time: O(n * 2^n), Space: O(n * 2^n)
 */
class Solution final {
public:
    [[nodiscard]] static auto shortestPathLength(
        const std::vector<std::vector<int>>& graph) -> int {
        const int n = static_cast<int>(graph.size());
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(1 << n, false));
        
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i);
            vis[i][1 << i] = true;
        }
        
        for (int ans = 0;; ++ans) {
            for (int k = static_cast<int>(q.size()); k > 0; --k) {
                auto [i, st] = q.front();
                q.pop();
                
                if (st == (1 << n) - 1) {
                    return ans;
                }
                
                for (const int j : graph[i]) {
                    const int nst = st | (1 << j);
                    if (!vis[j][nst]) {
                        vis[j][nst] = true;
                        q.emplace(j, nst);
                    }
                }
            }
        }
    }
};

/**
 * @brief Dijkstra's algorithm on subdivided graph
 * @intuition Each edge becomes cnt+1 edges; count reachable original and new nodes
 * @approach Run Dijkstra treating edge weights as cnt+1. Count reachable original nodes
 *           (dist <= maxMoves). For each edge, count reachable new nodes from both ends.
 * @complexity Time: O(E log V), Space: O(V + E)
 */
class Solution final {
public:
    [[nodiscard]] static auto reachableNodes(
        const std::vector<std::vector<int>>& edges, int maxMoves, int n) -> int {
        using pii = std::pair<int, int>;
        std::vector<std::vector<pii>> g(n);
        
        for (const auto& e : edges) {
            const int u = e[0], v = e[1], cnt = e[2] + 1;
            g[u].emplace_back(v, cnt);
            g[v].emplace_back(u, cnt);
        }
        
        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
        pq.emplace(0, 0);
        std::vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            for (auto [v, cnt] : g[u]) {
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    pq.emplace(dist[v], v);
                }
            }
        }
        
        int ans = 0;
        for (const int d : dist) {
            ans += (d <= maxMoves);
        }
        
        for (const auto& e : edges) {
            const int u = e[0], v = e[1], cnt = e[2];
            const int a = std::min(cnt, std::max(0, maxMoves - dist[u]));
            const int b = std::min(cnt, std::max(0, maxMoves - dist[v]));
            ans += std::min(cnt, a + b);
        }
        return ans;
    }
};

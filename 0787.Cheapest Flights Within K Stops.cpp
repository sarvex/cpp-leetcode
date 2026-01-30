/**
 * @brief Cheapest flight with at most k stops using Bellman-Ford
 * @intuition Relax edges k+1 times to allow k stops
 * @approach Modified Bellman-Ford with backup array for iteration limit
 * @complexity Time: O(k * E), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findCheapestPrice(const int n,
                                                const std::vector<std::vector<int>>& flights,
                                                const int src, const int dst, const int k) {
        constexpr int INF = 0x3f3f3f3f;
        std::vector<int> dist(n, INF);
        dist[src] = 0;
        
        for (int i = 0; i <= k; ++i) {
            std::vector<int> backup = dist;
            for (const auto& edge : flights) {
                const int from = edge[0];
                const int to = edge[1];
                const int price = edge[2];
                dist[to] = std::min(dist[to], backup[from] + price);
            }
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};

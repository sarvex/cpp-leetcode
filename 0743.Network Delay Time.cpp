/**
 * @brief Network delay time using Dijkstra's algorithm
 * @intuition Find shortest paths from source to all nodes, return maximum
 * @approach Dijkstra's algorithm to find single-source shortest paths
 * @complexity Time: O(n^2), Space: O(n^2)
 */
class Solution final {
public:
    [[nodiscard]] static int networkDelayTime(const std::vector<std::vector<int>>& times, 
                                               const int n, const int k) {
        constexpr int INF = 1 << 29;
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, INF));
        
        for (const auto& edge : times) {
            graph[edge[0] - 1][edge[1] - 1] = edge[2];
        }
        
        std::vector<int> dist(n, INF);
        dist[k - 1] = 0;
        std::vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            int closest = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (closest == -1 || dist[closest] > dist[j])) {
                    closest = j;
                }
            }
            visited[closest] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = std::min(dist[j], dist[closest] + graph[closest][j]);
            }
        }
        
        const int result = std::ranges::max(dist);
        return result == INF ? -1 : result;
    }
};

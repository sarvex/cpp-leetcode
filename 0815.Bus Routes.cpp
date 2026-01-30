/**
 * @brief BFS on bus routes graph to find minimum buses to destination
 * @intuition Build stop-to-routes mapping and BFS through bus connections
 * @approach Create graph mapping stops to bus routes. BFS from source stop,
 *           exploring all buses at current stop and their connected stops.
 *           Track visited buses and stops to avoid cycles.
 * @complexity Time: O(sum of route lengths), Space: O(stops + routes)
 */
class Solution final {
public:
    [[nodiscard]] static auto numBusesToDestination(
        const std::vector<std::vector<int>>& routes,
        int source, int target) -> int {
        if (source == target) return 0;
        
        std::unordered_map<int, std::vector<int>> g;
        for (int i = 0; i < static_cast<int>(routes.size()); ++i) {
            for (const int stop : routes[i]) {
                g[stop].push_back(i);
            }
        }
        
        if (!g.contains(source) || !g.contains(target)) {
            return -1;
        }
        
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> visBus;
        std::unordered_set<int> visStop;
        q.push({source, 0});
        visStop.insert(source);
        
        while (!q.empty()) {
            auto [stop, busCount] = q.front();
            q.pop();
            
            if (stop == target) return busCount;
            
            for (const int bus : g[stop]) {
                if (!visBus.contains(bus)) {
                    visBus.insert(bus);
                    for (const int nextStop : routes[bus]) {
                        if (!visStop.contains(nextStop)) {
                            visStop.insert(nextStop);
                            q.push({nextStop, busCount + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

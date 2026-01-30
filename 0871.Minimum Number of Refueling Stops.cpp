/**
 * @brief Greedy refueling using max-heap of available fuel
 * @intuition Collect fuel from passed stations; refuel from largest when needed
 * @approach Process stations in order. Add fuel to max-heap when passing. When
 *           fuel runs out before next station, refuel from heap (largest first).
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto minRefuelStops(int target, int startFuel,
        std::vector<std::vector<int>>& stations) -> int {
        std::priority_queue<int> pq;
        stations.push_back({target, 0});
        
        int ans = 0, pre = 0;
        for (const auto& station : stations) {
            const int pos = station[0], fuel = station[1];
            const int dist = pos - pre;
            startFuel -= dist;
            
            while (startFuel < 0 && !pq.empty()) {
                startFuel += pq.top();
                pq.pop();
                ++ans;
            }
            
            if (startFuel < 0) return -1;
            
            pq.push(fuel);
            pre = pos;
        }
        return ans;
    }
};

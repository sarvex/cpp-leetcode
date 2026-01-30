/**
 * @brief Sort by position and count distinct arrival times
 * @intuition Cars closer to target can block faster cars behind them forming fleets
 * @approach Sort cars by position descending. Track latest arrival time. If a car
 *           arrives later than current fleet, it forms a new fleet.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto carFleet(int target,
                                        const std::vector<int>& position,
                                        const std::vector<int>& speed) -> int {
        const int n = static_cast<int>(position.size());
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        
        std::ranges::sort(idx, [&](int i, int j) {
            return position[i] > position[j];
        });
        
        int ans = 0;
        double pre = 0;
        
        for (const int i : idx) {
            const double t = 1.0 * (target - position[i]) / speed[i];
            if (t > pre) {
                ++ans;
                pre = t;
            }
        }
        return ans;
    }
};

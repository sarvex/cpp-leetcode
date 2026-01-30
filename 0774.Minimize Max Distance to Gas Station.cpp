/**
 * @brief Minimize maximum distance between gas stations
 * @intuition Binary search on answer; check if k stations can achieve distance d
 * @approach Binary search on distance, count required stations for each gap
 * @complexity Time: O(n log(range/precision)), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static double minmaxGasDist(const std::vector<int>& stations, const int k) {
        double left = 0;
        double right = 1e8;
        
        auto canAchieve = [&](double maxDist) -> bool {
            int stationsNeeded = 0;
            for (size_t i = 0; i + 1 < stations.size(); ++i) {
                stationsNeeded += static_cast<int>((stations[i + 1] - stations[i]) / maxDist);
            }
            return stationsNeeded <= k;
        };
        
        while (right - left > 1e-6) {
            const double mid = (left + right) / 2.0;
            if (canAchieve(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};

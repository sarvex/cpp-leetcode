/**
 * @brief Find minimum distance between two bus stops in circular route
 * @intuition Compare clockwise and counter-clockwise distances
 * @approach Sum total distance around circuit. Calculate one-way distance from start to destination.
 *           Return minimum of this distance and (total - distance).
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int distanceBetweenBusStops(const vector<int>& distance, int start,
                                                      const int destination) {
        int s = accumulate(distance.begin(), distance.end(), 0);
        int t = 0;
        const int n = distance.size();
        while (start != destination) {
            t += distance[start];
            start = (start + 1) % n;
        }
        return min(t, s - t);
    }
};

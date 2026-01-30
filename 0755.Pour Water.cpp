/**
 * @brief Simulate pouring water droplets
 * @intuition Water flows left first, then right, then stays at k
 * @approach For each drop, find lowest position left of k, else right, else k
 * @complexity Time: O(volume * n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> pourWater(std::vector<int>& heights, 
                                                     int volume, const int k) {
        const int n = static_cast<int>(heights.size());
        
        while (volume--) {
            bool placed = false;
            for (int dir = -1; dir <= 1 && !placed; dir += 2) {
                int i = k;
                int lowestPos = k;
                while (i + dir >= 0 && i + dir < n && heights[i + dir] <= heights[i]) {
                    if (heights[i + dir] < heights[i]) {
                        lowestPos = i + dir;
                    }
                    i += dir;
                }
                if (lowestPos != k) {
                    placed = true;
                    ++heights[lowestPos];
                }
            }
            if (!placed) {
                ++heights[k];
            }
        }
        return heights;
    }
};

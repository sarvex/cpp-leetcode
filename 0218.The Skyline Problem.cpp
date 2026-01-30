/**
 * @brief Coordinate compression with height tracking for skyline
 * @intuition Track maximum height at each x-coordinate, output height changes
 * @approach Map coordinates to indices, compute max heights, detect changes
 * @complexity Time: O(n^2), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto getSkyline(const std::vector<std::vector<int>>& buildings) -> std::vector<std::vector<int>> {
        std::set<int> positions;
        for (const auto& building : buildings) {
            positions.insert(building[0]);
            positions.insert(building[1]);
        }
        
        std::map<int, int> positionToIndex;
        int index = 0;
        for (const int pos : positions) {
            positionToIndex[pos] = index++;
        }
        
        std::vector<int> heights(positionToIndex.size(), 0);
        for (const auto& building : buildings) {
            const int left = positionToIndex[building[0]];
            const int right = positionToIndex[building[1]];
            const int height = building[2];
            for (int i = left; i < right; ++i) {
                heights[i] = std::max(heights[i], height);
            }
        }
        
        std::vector<std::vector<int>> result;
        const std::vector<int> sortedPositions(positions.begin(), positions.end());
        
        for (std::size_t i = 0; i < heights.size(); ++i) {
            const int currentHeight = heights[i];
            const int prevHeight = (i == 0) ? -1 : heights[i - 1];
            if (currentHeight != prevHeight) {
                result.push_back({sortedPositions[i], currentHeight});
            }
        }
        
        return result;
    }
};

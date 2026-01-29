/**
 * @brief Coordinate compression with height tracking for skyline
 * @intuition Track maximum height at each x-coordinate, output height changes
 * @approach Map coordinates to indices, compute max heights, detect changes
 * @complexity Time: O(n^2), Space: O(n)
 */
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto getSkyline(const std::vector<std::vector<int>>& buildings) const 
      -> std::vector<std::pair<int, int>> {
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
    
    std::vector<std::pair<int, int>> result;
    const std::vector<int> sortedPositions(positions.begin(), positions.end());
    
    for (std::size_t i = 0; i < heights.size(); ++i) {
      if (i == heights.size() - 1 || heights[i] != heights[i + 1]) {
        result.emplace_back(sortedPositions[i], heights[i]);
      } else {
        result.emplace_back(sortedPositions[i], heights[i]);
        while (i < heights.size() - 1 && heights[i] == heights[i + 1]) {
          ++i;
        }
      }
    }
    return result;
  }
};

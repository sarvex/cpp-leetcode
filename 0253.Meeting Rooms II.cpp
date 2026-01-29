/**
 * @brief Difference array for concurrent meeting count
 * @intuition Track delta at start/end times, max prefix sum is answer
 * @approach Increment at start, decrement at end, compute max concurrent
 * @complexity Time: O(n + m) where m is max end time, Space: O(m)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto minMeetingRooms(const std::vector<std::vector<int>>& intervals) const -> int {
    int maxTime = 0;
    for (const auto& interval : intervals) {
      maxTime = std::max(maxTime, interval[1]);
    }
    
    std::vector<int> delta(maxTime + 1);
    for (const auto& interval : intervals) {
      ++delta[interval[0]];
      --delta[interval[1]];
    }
    
    int maxRooms = 0;
    int currentRooms = 0;
    for (const int change : delta) {
      currentRooms += change;
      maxRooms = std::max(maxRooms, currentRooms);
    }
    return maxRooms;
  }
};

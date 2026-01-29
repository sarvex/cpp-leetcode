/**
 * @brief Merge overlapping intervals
 * @intuition Sort by start time, then merge consecutive overlapping intervals
 * @approach Sort intervals, extend current interval or add new one based on overlap
 * @complexity Time: O(n log n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto merge(std::vector<std::vector<int>>& intervals)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(intervals);

    int start = intervals[0][0];
    int end = intervals[0][1];
    std::vector<std::vector<int>> result;

    for (std::size_t i = 1; i < intervals.size(); ++i) {
      if (end < intervals[i][0]) {
        result.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      } else {
        end = std::max(end, intervals[i][1]);
      }
    }

    result.push_back({start, end});
    return result;
  }
};

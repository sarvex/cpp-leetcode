/**
 * @brief Insert a new interval into sorted non-overlapping intervals
 * @intuition Add new interval and merge all overlapping intervals
 * @approach Append new interval to list and use merge algorithm
 * @complexity Time: O(n log n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto insert(std::vector<std::vector<int>>& intervals,
                                   std::vector<int>& newInterval)
      -> std::vector<std::vector<int>> {
    intervals.emplace_back(newInterval);
    return merge(intervals);
  }

private:
  [[nodiscard]] static auto merge(std::vector<std::vector<int>>& intervals)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(intervals);
    std::vector<std::vector<int>> result;
    result.emplace_back(intervals[0]);

    for (std::size_t i = 1; i < intervals.size(); ++i) {
      if (result.back()[1] < intervals[i][0]) {
        result.emplace_back(intervals[i]);
      } else {
        result.back()[1] = std::max(result.back()[1], intervals[i][1]);
      }
    }

    return result;
  }
};

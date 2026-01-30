/**
 * @brief Sort intervals to detect meeting overlaps
 * @intuition After sorting by start time, check if any meeting overlaps next
 * @approach Sort then check consecutive intervals for overlap
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static auto canAttendMeetings(std::vector<std::vector<int>>& intervals) -> bool {
    std::ranges::sort(intervals, [](const auto& a, const auto& b) { return a[0] < b[0]; });
    
    for (std::size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i - 1][1] > intervals[i][0]) {
        return false;
      }
    }
    return true;
  }
};

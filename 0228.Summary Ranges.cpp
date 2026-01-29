/**
 * @brief Group consecutive numbers into ranges
 * @intuition Consecutive numbers form ranges, track start and end
 * @approach Two-pointer to find consecutive sequences, format as strings
 * @complexity Time: O(n), Space: O(1) excluding output
 */
#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto summaryRanges(const std::vector<int>& nums) const -> std::vector<std::string> {
    std::vector<std::string> result;
    const auto n = nums.size();
    
    auto formatRange = [&nums](std::size_t start, std::size_t end) -> std::string {
      if (start == end) {
        return std::to_string(nums[start]);
      }
      return std::to_string(nums[start]) + "->" + std::to_string(nums[end]);
    };
    
    for (std::size_t i = 0; i < n;) {
      std::size_t j = i;
      while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
        ++j;
      }
      result.push_back(formatRange(i, j));
      i = j + 1;
    }
    return result;
  }
};

/**
 * @brief Sorting to detect duplicates
 * @intuition After sorting, duplicates become adjacent
 * @approach Sort array and check adjacent elements
 * @complexity Time: O(n log n), Space: O(1) or O(n) depending on sort
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto containsDuplicate(std::vector<int>& nums) const -> bool {
    std::sort(nums.begin(), nums.end());
    for (std::size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

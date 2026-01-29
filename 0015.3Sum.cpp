/**
 * @brief Two-pointer approach for finding all unique triplets that sum to zero
 * @intuition Sorting enables efficient duplicate skipping and two-pointer search
 * @approach Sort, iterate with fixed first element, use two pointers for the rest
 * @complexity Time: O(n^2), Space: O(1) excluding output
 */

#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto threeSum(std::vector<int>& nums)
      -> std::vector<std::vector<int>> {
    std::ranges::sort(nums);
    std::vector<std::vector<int>> result;
    const auto n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = n - 1;

      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          ++left;
        } else if (sum > 0) {
          --right;
        } else {
          result.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) {
            ++left;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            --right;
          }
          ++left;
          --right;
        }
      }
    }

    return result;
  }
};

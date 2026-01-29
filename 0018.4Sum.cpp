/**
 * @brief Four sum using two-pointer technique after sorting
 * @intuition Reduce 4Sum to 2Sum by fixing two indices and using two pointers
 * @approach Sort, skip duplicates, use nested loops then two-pointer
 * @complexity Time: O(n^3), Space: O(1) excluding output
 */

#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto fourSum(std::vector<int>& nums, const int target)
      -> std::vector<std::vector<int>> {
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> result;

    if (n < 4) {
      return result;
    }

    std::ranges::sort(nums);

    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        int left = j + 1;
        int right = n - 1;

        while (left < right) {
          const auto sum = static_cast<long long>(nums[i]) + nums[j] +
                           nums[left] + nums[right];
          if (sum < target) {
            ++left;
          } else if (sum > target) {
            --right;
          } else {
            result.push_back({nums[i], nums[j], nums[left], nums[right]});
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
    }

    return result;
  }
};

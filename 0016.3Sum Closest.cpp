/**
 * @brief Two-pointer approach for 3Sum Closest problem
 * @intuition Sort and use two pointers to scan for closest sum
 * @approach Fix one element, use two pointers for the rest, update closest sum
 * @complexity Time: O(n^2), Space: O(1)
 */

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto threeSumClosest(std::vector<int>& nums,
                                            const int target) -> int {
    std::ranges::sort(nums);
    int closest = std::numeric_limits<int>::max();

    for (size_t i = 0; i + 2 < nums.size(); ++i) {
      size_t left = i + 1;
      size_t right = nums.size() - 1;

      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];
        if (sum == target) {
          return sum;
        }
        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }
        if (sum < target) {
          ++left;
        } else {
          --right;
        }
      }
    }

    return closest;
  }
};

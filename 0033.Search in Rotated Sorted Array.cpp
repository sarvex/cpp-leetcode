/**
 * @brief Binary search in rotated sorted array
 * @intuition Determine which half is sorted, then decide search direction
 * @approach Modified binary search checking which side is ordered
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto search(const std::vector<int>& nums,
                                   const int target) -> int {
    const int n = static_cast<int>(nums.size());
    int left = 0;
    int right = n - 1;

    while (left < right) {
      const int mid = left + (right - left) / 2;

      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target <= nums[mid]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[n - 1]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
    }

    return nums[left] == target ? left : -1;
  }
};

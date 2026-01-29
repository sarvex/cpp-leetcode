/**
 * @brief Two-pointer approach for counting 3-sum combinations
 * @intuition Sort array, fix first element, use two pointers for rest
 * @approach When sum < target, all pairs with current j count
 * @complexity Time: O(n^2), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto threeSumSmaller(std::vector<int>& nums, int target) const -> int {
    std::sort(nums.begin(), nums.end());
    int count = 0;
    const auto n = static_cast<int>(nums.size());
    
    for (int i = 0; i + 2 < n; ++i) {
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];
        if (sum < target) {
          count += right - left;
          ++left;
        } else {
          --right;
        }
      }
    }
    return count;
  }
};

/**
 * @brief Find index where target should be inserted to keep sorted order
 * @intuition Binary search for insertion point
 * @approach Use lower_bound semantics in binary search
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto searchInsert(const std::vector<int>& nums,
                                         const int target) -> int {
    int left = 0;
    int right = static_cast<int>(nums.size());

    while (left < right) {
      const int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};

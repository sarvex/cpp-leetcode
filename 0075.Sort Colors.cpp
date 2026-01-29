/**
 * @brief Sort array containing only 0, 1, and 2 (Dutch National Flag)
 * @intuition Use three pointers to partition array into three sections
 * @approach Maintain boundaries for 0s and 2s, swap elements to correct positions
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  static auto sortColors(std::vector<int>& nums) -> void {
    int i = -1;
    int j = static_cast<int>(nums.size());
    int k = 0;

    while (k < j) {
      if (nums[k] == 0) {
        std::swap(nums[++i], nums[k++]);
      } else if (nums[k] == 2) {
        std::swap(nums[--j], nums[k]);
      } else {
        ++k;
      }
    }
  }
};

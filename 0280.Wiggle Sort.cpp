/**
 * @brief Single pass wiggle sort in place
 * @intuition At odd indices need nums[i] >= nums[i-1], at even need nums[i] <= nums[i-1]
 * @approach Swap adjacent elements when wiggle property violated
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
  static auto wiggleSort(std::vector<int>& nums) -> void {
    for (std::size_t i = 1; i < nums.size(); ++i) {
      const bool shouldSwap = (i % 2 == 1 && nums[i] < nums[i - 1]) || 
                              (i % 2 == 0 && nums[i] > nums[i - 1]);
      if (shouldSwap) {
        std::swap(nums[i], nums[i - 1]);
      }
    }
  }
};

/**
 * @brief Rearrange to the next lexicographically greater permutation
 * @intuition Find rightmost ascending pair, swap, and reverse suffix
 * @approach Find pivot, swap with smallest larger element, reverse suffix
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  static auto nextPermutation(std::vector<int>& nums) -> void {
    const int n = static_cast<int>(nums.size());
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
      --i;
    }

    if (i >= 0) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] > nums[i]) {
          std::swap(nums[i], nums[j]);
          break;
        }
      }
    }

    std::reverse(nums.begin() + i + 1, nums.end());
  }
};

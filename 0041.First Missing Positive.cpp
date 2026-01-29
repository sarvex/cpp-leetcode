/**
 * @brief Find the smallest missing positive integer in O(n) time and O(1) space
 * @intuition Use the array itself as a hash table
 * @approach Place each number at its corresponding index (1 at index 0, etc.)
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto firstMissingPositive(std::vector<int>& nums)
      -> int {
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return n + 1;
  }
};

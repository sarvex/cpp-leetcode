/**
 * @brief XOR to find missing number
 * @intuition XOR of all indices and values leaves only missing number
 * @approach XOR all values with all indices 0 to n
 * @complexity Time: O(n), Space: O(1)
 */
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto missingNumber(const std::vector<int>& nums) const -> int {
    const auto n = static_cast<int>(nums.size());
    int result = n;
    for (int i = 0; i < n; ++i) {
      result ^= (i ^ nums[i]);
    }
    return result;
  }
};

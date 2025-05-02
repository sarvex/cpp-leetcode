#include <span>
#include <vector>

using std::span;
using std::vector;

class Solution {
public:
  /**
   * @brief Product of array except self, generic and constexpr-friendly.
   * @intuition: Prefix and suffix products, no division, minimal memory.
   * @approach: Use std::span for genericity, single output vector,
   * forward/backward passes.
   * @complexity: Time O(n), Space O(1) extra (excluding output).
   */
  [[nodiscard]] std::vector<int> productExceptSelf(span<const int> nums) const {
    const auto n = static_cast<int>(nums.size());
    vector<int> result(n, 1);
    int prefix = 1, suffix = 1;
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      result[i] *= prefix;
      result[j] *= suffix;
      prefix *= nums[i];
      suffix *= nums[j];
    }
    return result;
  }
};

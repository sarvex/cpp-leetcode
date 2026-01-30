/**
 * @brief Product of array except self using prefix/suffix products
 * @intuition Each position is product of all elements before and after
 * @approach Single pass computing prefix and suffix products simultaneously
 * @complexity Time: O(n), Space: O(1) extra excluding output
 */

class Solution final {
public:
  [[nodiscard]] static auto productExceptSelf(const std::vector<int>& nums) -> std::vector<int> {
    const auto n = static_cast<int>(nums.size());
    std::vector<int> result(n, 1);
    int prefix = 1;
    int suffix = 1;
    
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      result[i] *= prefix;
      result[j] *= suffix;
      prefix *= nums[i];
      suffix *= nums[j];
    }
    return result;
  }
};

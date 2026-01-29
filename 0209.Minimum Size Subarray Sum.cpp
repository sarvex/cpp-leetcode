/**
 * @brief Binary search on prefix sums for minimum subarray
 * @intuition Find shortest subarray with sum >= target using prefix sums
 * @approach Compute prefix sums and binary search for valid subarrays
 * @complexity Time: O(n log n), Space: O(n)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto minSubArrayLen(int target, const std::vector<int>& nums) const -> int {
    const auto n = nums.size();
    std::vector<long long> prefixSum(n + 1);
    
    for (std::size_t i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    auto minLength = n + 1;
    for (std::size_t i = 0; i <= n; ++i) {
      const auto targetSum = prefixSum[i] + target;
      const auto it = std::lower_bound(prefixSum.begin(), prefixSum.end(), targetSum);
      if (it != prefixSum.end()) {
        const auto j = static_cast<std::size_t>(std::distance(prefixSum.begin(), it));
        minLength = std::min(minLength, j - i);
      }
    }
    
    return minLength <= n ? static_cast<int>(minLength) : 0;
  }
};

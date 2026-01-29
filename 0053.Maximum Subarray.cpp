/**
 * @brief Find the contiguous subarray with the largest sum (Kadane's Algorithm)
 * @intuition At each step, decide whether to extend the current subarray or start fresh
 * @approach Track current sum and max sum, reset when sum becomes negative
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto maxSubArray(std::vector<int> const& nums) -> int {
    if (nums.empty()) {
      return 0;
    }

    int currentSum = nums[0];
    int maxSum = currentSum;

    for (std::size_t i = 1; i < nums.size(); ++i) {
      currentSum = std::max(nums[i], currentSum + nums[i]);
      maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
  }
};

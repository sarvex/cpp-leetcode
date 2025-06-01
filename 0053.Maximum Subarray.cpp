#include <vector>

class Solution final {
public:
/**
 * Find the contiguous subarray with the largest sum (Kadane's Algorithm).
 *
 * @intuition At each step, decide whether to extend the current subarray or start a new subarray
 *            from the current element based on which gives a larger sum.
 *
 * @approach Uses Kadane's algorithm which maintains two variables:
 *           - current_sum: Maximum sum ending at current index
 *           - max_sum: Maximum sum found so far
 *           For each element, update current_sum to be the maximum of the current element or
 *           the sum of current_sum + current element. Then update max_sum accordingly.
 *
 * @complexity
 * - Time:   O(n), where n is the size of the input array.
 *            We traverse the array exactly once.
 * - Space:  O(1), as we use constant extra space.
 */    int maxSubArray(vector<int>& nums) const noexcept {
        if (nums.empty()) return 0;

        auto current_sum = nums[0];
        auto max_sum = current_sum;

        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            current_sum = std::max(*it, current_sum + *it);
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};

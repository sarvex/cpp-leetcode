/**
 * @brief Count subarrays with product less than k using sliding window
 * @intuition Maintain window where product < k, shrink from left when violated
 * @approach Two pointers: expand right, shrink left, count valid subarrays ending at right
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int numSubarrayProductLessThanK(const std::vector<int>& nums, const int k) {
        int result = 0;
        int left = 0;
        int product = 1;
        
        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            product *= nums[right];
            while (left <= right && product >= k) {
                product /= nums[left++];
            }
            result += right - left + 1;
        }
        return result;
    }
};

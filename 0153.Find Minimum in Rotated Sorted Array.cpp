/**
 * @brief Find minimum in rotated sorted array using binary search
 * @intuition Min is at rotation point where order is broken
 * @approach Binary search comparing with first element to find rotation point
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto findMin(const std::vector<int>& nums) -> int {
        const int n = static_cast<int>(nums.size());
        
        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }
        
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[0] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};

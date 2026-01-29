/**
 * @brief Find minimum in rotated sorted array with duplicates using modified binary search
 * @intuition Handle duplicates by shrinking search space when elements equal
 * @approach Compare with rightmost element, shrink right when equal
 * @complexity Time: O(log n) average, O(n) worst case, Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto findMin(const std::vector<int>& nums) -> int {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                --right;
            }
        }
        
        return nums[left];
    }
};

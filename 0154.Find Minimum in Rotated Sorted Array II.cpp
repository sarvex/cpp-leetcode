/**
 * @brief Find minimum in rotated sorted array with duplicates using modified binary search
 * @intuition Handle duplicates by shrinking search space when elements equal
 * @approach Compare with rightmost element, shrink right when equal
 * @complexity Time: O(log n) average, O(n) worst case, Space: O(1)
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto findMin(vector<int>& nums) const -> int {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // Min is in right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Min is in left half including mid
                right = mid;
            } else {
                // Can't determine, shrink search space
                --right;
            }
        }
        
        return nums[left];
    }
};

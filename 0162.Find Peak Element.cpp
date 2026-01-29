/**
 * @brief Find peak element using binary search
 * @intuition Peak exists where element is greater than neighbors; binary search to find
 * @approach Move towards ascending direction; peak guaranteed to exist
 * @complexity Time: O(log n), Space: O(1)
 */

#include <vector>

using std::vector;

class Solution final {
public:
    [[nodiscard]] auto findPeakElement(vector<int>& nums) const -> int {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Descending, peak is at mid or left
                right = mid;
            } else {
                // Ascending, peak is to the right
                left = mid + 1;
            }
        }
        
        return left;
    }
};

/**
 * @brief Find peak element using binary search
 * @intuition Peak exists where element is greater than neighbors; binary search to find
 * @approach Move towards ascending direction; peak guaranteed to exist
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto findPeakElement(const std::vector<int>& nums) -> int {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

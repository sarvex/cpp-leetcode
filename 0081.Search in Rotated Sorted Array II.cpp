/**
 * @brief Binary search in rotated sorted array with duplicates
 * @intuition Modified binary search handling rotation pivot and duplicates
 * @approach Compare mid with right to determine sorted half; handle duplicates
 *           by shrinking range when mid equals right
 * @complexity Time: O(log n) average, O(n) worst case with duplicates, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto search(const vector<int>& nums, const int target) -> bool {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                --right;
            }
        }
        return nums[left] == target;
    }
};

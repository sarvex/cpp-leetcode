/**
 * @brief Standard binary search implementation
 * @intuition Halve search space each iteration by comparing middle element
 * @approach Use left-closed, right-open interval to find lower bound
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int search(const std::vector<int>& nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
};

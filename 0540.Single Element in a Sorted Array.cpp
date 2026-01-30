/**
 * @brief Find single non-duplicate element in sorted array using binary search
 * @intuition Before single element, pairs are at (even, odd) indices; after, at (odd, even)
 * @approach Binary search: at mid, check if paired with mid^1 (XOR toggles last bit).
 *           If paired correctly, single element is to the right; otherwise to the left.
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto singleNonDuplicate(const vector<int>& nums) -> int {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (nums[mid] != nums[mid ^ 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

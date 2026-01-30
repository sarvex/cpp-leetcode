/**
 * @brief Check if target appears more than n/2 times in sorted array
 * @intuition Use binary search to find range of target values in sorted array
 * @approach Find first and last occurrence using lower_bound and upper_bound.
 *           Check if count exceeds half the array size.
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isMajorityElement(const vector<int>& nums, const int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        return right - left > nums.size() / 2;
    }
};

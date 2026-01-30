/**
 * @brief Sorting to detect duplicates
 * @intuition After sorting, duplicates become adjacent
 * @approach Sort array and check adjacent elements
 * @complexity Time: O(n log n), Space: O(1) or O(n) depending on sort
 */

class Solution final {
public:
    [[nodiscard]] static auto containsDuplicate(std::vector<int>& nums) -> bool {
        std::ranges::sort(nums);
        for (std::size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

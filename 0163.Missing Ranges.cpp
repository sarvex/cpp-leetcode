/**
 * @brief Find missing ranges in sorted array within given bounds
 * @intuition Gap exists when consecutive elements differ by more than 1
 * @approach Scan array checking gaps, including boundaries at start and end
 * @complexity Time: O(n), Space: O(1) excluding output
 */

class Solution final {
public:
    [[nodiscard]] static auto findMissingRanges(const std::vector<int>& nums, int lower, int upper)
        -> std::vector<std::vector<int>> {
        const int n = static_cast<int>(nums.size());
        
        if (n == 0) {
            return {{lower, upper}};
        }
        
        std::vector<std::vector<int>> result;
        
        if (nums[0] > lower) {
            result.push_back({lower, nums[0] - 1});
        }
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 1) {
                result.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        
        if (nums[n - 1] < upper) {
            result.push_back({nums[n - 1] + 1, upper});
        }
        
        return result;
    }
};

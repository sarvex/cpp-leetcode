/**
 * @brief Check if array can become non-decreasing with at most one modification
 * @intuition At first violation, try fixing either element and verify sorted
 * @approach Find first decrease, try both fixes, check if either results in sorted array
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            const int a = nums[i];
            const int b = nums[i + 1];
            
            if (a > b) {
                nums[i] = b;
                if (ranges::is_sorted(nums)) {
                    return true;
                }
                nums[i] = a;
                nums[i + 1] = a;
                return ranges::is_sorted(nums);
            }
        }
        return true;
    }
};

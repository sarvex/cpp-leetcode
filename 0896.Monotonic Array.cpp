/**
 * @brief Check if array is monotonically increasing or decreasing
 * @intuition Array is monotonic if it never both increases and decreases
 * @approach Track if we've seen an increase and a decrease. If both seen,
 *           array is not monotonic.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto isMonotonic(const std::vector<int>& nums) -> bool {
        bool asc = false, desc = false;
        const int n = static_cast<int>(nums.size());
        
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                asc = true;
            } else if (nums[i - 1] > nums[i]) {
                desc = true;
            }
            if (asc && desc) return false;
        }
        return true;
    }
};

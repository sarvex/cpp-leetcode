/**
 * @brief Dynamic programming with state compression for minimum swaps
 * @intuition Track two states: minimum swaps if we swap at current position vs not swap
 * @approach Use DP where 'a' represents min swaps without swapping current element and 'b'
 *           represents min swaps with swapping. For each position, if previous elements violate
 *           strictly increasing property, we must swap. Otherwise, we can choose optimally.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto minSwap(const std::vector<int>& nums1,
                                       const std::vector<int>& nums2) -> int {
        const int n = static_cast<int>(nums1.size());
        int a = 0, b = 1;
        
        for (int i = 1; i < n; ++i) {
            const int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y;
                b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = std::min(a, y);
                    b = std::min(b, x + 1);
                }
            }
        }
        return std::min(a, b);
    }
};

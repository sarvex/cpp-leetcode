/**
 * @brief Calculate minimum range after adding [-k, k] to elements
 * @intuition The minimum possible range is (max - min - 2*k) or 0
 * @approach Find min and max, reduce range by 2k from both sides
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int smallestRangeI(const vector<int>& nums, const int k) {
        const auto [mi, mx] = ranges::minmax_element(nums);
        return max(0, *mx - *mi - k * 2);
    }
};

/**
 * @brief Clear lowest set bits approach
 * @intuition The AND of a range will keep only common prefix bits of left and right
 * @approach Repeatedly clear the lowest set bit of right until right <= left
 * @complexity Time: O(log n) where n is the difference, Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static constexpr auto rangeBitwiseAnd(int left, int right) noexcept -> int {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};

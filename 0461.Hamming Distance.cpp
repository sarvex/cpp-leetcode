/**
 * @brief Count differing bits between two integers
 * @intuition XOR gives 1 for differing bits, count set bits in result
 * @approach Use builtin popcount on XOR result
 * @complexity Time: O(1) Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] auto hammingDistance(int x, int y) const -> int {
        return __builtin_popcount(x ^ y);
    }
};

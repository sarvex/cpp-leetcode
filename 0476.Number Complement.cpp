/**
 * @brief Find complement of a positive integer
 * @intuition XOR with all 1s of same bit length flips all bits
 * @approach Create mask with all 1s up to highest set bit, XOR with num
 * @complexity Time: O(1), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] auto findComplement(int num) const -> int {
        return num ^ ((1LL << (64 - __builtin_clzll(num))) - 1);
    }
};

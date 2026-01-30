/**
 * @brief Bit-by-bit complement construction
 * @intuition Flip each bit of the number from LSB to MSB
 * @approach Extract bits, flip them, and accumulate result
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= ((n & 1) ^ 1) << i++;
            n >>= 1;
        }
        return ans;
    }
};

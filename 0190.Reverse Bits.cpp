/**
 * @brief Reverse bits of 32-bit unsigned integer
 * @intuition Build result bit by bit from LSB to MSB of input
 * @approach Extract each bit from input and place in reversed position
 * @complexity Time: O(32) = O(1), Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto reverseBits(uint32_t n) -> uint32_t {
        uint32_t result = 0;
        
        for (int i = 0; i < 32 && n != 0; ++i) {
            result |= (n & 1) << (31 - i);
            n >>= 1;
        }
        
        return result;
    }
};

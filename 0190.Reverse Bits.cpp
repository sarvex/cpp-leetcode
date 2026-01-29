/**
 * @brief Reverse bits of 32-bit unsigned integer
 * @intuition Build result bit by bit from LSB to MSB of input
 * @approach Extract each bit from input and place in reversed position
 * @complexity Time: O(32) = O(1), Space: O(1)
 */

#include <cstdint>

class Solution final {
public:
    [[nodiscard]] auto reverseBits(uint32_t n) const -> uint32_t {
        uint32_t result = 0;
        
        for (int i = 0; i < 32 && n != 0; ++i) {
            result |= (n & 1) << (31 - i);
            n >>= 1;
        }
        
        return result;
    }
};

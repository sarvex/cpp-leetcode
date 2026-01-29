/**
 * @brief Count number of 1 bits (Hamming weight) using Brian Kernighan's algorithm
 * @intuition n & (n-1) clears the lowest set bit
 * @approach Repeatedly clear lowest set bit and count iterations
 * @complexity Time: O(k) where k is number of 1 bits, Space: O(1)
 */

class Solution final {
public:
    [[nodiscard]] static auto hammingWeight(uint32_t n) -> int {
        int count = 0;
        
        while (n != 0) {
            n &= n - 1;
            ++count;
        }
        
        return count;
    }
};

/**
 * @brief Check if number is a power of four
 * @intuition Power of 4 is power of 2 with single bit at even position
 * @approach Check power of 2 and bit position using mask 0xAAAAAAAA
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static constexpr bool isPowerOfFour(const int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }
};

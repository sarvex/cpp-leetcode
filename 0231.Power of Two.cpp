/**
 * @brief Bit manipulation to check power of two
 * @intuition Power of 2 has exactly one bit set; n & (n-1) clears lowest bit
 * @approach Check if n > 0 and has only one bit set
 * @complexity Time: O(1), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static constexpr auto isPowerOfTwo(const int n) noexcept -> bool {
    return n > 0 && (n & (n - 1)) == 0;
  }
};

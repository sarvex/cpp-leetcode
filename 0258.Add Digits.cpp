/**
 * @brief Digital root using modular arithmetic
 * @intuition Digital root is 1 + (n-1) % 9 for n > 0
 * @approach Mathematical formula for digital root
 * @complexity Time: O(1), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static constexpr auto addDigits(int num) noexcept -> int {
    if (num == 0) {
      return 0;
    }
    return (num - 1) % 9 + 1;
  }
};

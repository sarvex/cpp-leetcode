class Solution {
public:
  /**
   * @brief Checks if an integer is a palindrome without converting to string.
   * @intuition: Reverse half the number and compare with the other half.
   * @approach: Reject negatives and numbers ending with zero (except zero
   * itself). Reverse digits until the original is less than or equal to the
   * reversed. Compare for equality.
   * @complexity: Time O(log₁₀n), Space O(1)
   */
  [[nodiscard]]
  static constexpr bool isPalindrome(const int x) noexcept {
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;
    int original = x, reversed = 0;
    while (original > reversed) {
      reversed = reversed * 10 + original % 10;
      original /= 10;
    }
    return original == reversed || original == reversed / 10;
  }
};

/**
 * @brief Checks if an integer is a palindrome without converting to string
 * @intuition Reverse half the number and compare with the other half
 * @approach Reject negatives and numbers ending with zero; reverse until halves meet
 * @complexity Time: O(log n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static constexpr auto isPalindrome(int x) noexcept -> bool {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int original = x;
    int reversed = 0;

    while (original > reversed) {
      reversed = reversed * 10 + original % 10;
      original /= 10;
    }

    return original == reversed || original == reversed / 10;
  }
};

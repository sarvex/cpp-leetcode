#include <string>
#include <vector>

class Solution {
public:
  /**
   * @brief Dynamic programming for longest palindromic substring.
   * @intuition: Palindromes expand from the center; DP can track valid substrings.
   * @approach: Use a DP table to mark palindromic substrings, updating max as we go.
   * @complexity: O(n^2) time, O(n^2) space.
   */
  [[nodiscard]] std::string longestPalindrome(const std::string& s) const {

    const auto n = static_cast<int>(s.size());

    if (n < 2) return s;
    std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; ++i) isPalindrome[i][i] = true;

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j] && (len == 2 || isPalindrome[i + 1][j - 1])) {
          isPalindrome[i][j] = true;
          if (len > maxLen) {
            start = i;
            maxLen = len;
          }
        }
      }
    }
    return s.substr(start, maxLen);
  }
};

/**
 * @brief Rolling hash to find longest palindrome prefix
 * @intuition Find longest palindrome starting at index 0, prepend reverse of remainder
 * @approach Use rolling hash to compare prefix and suffix simultaneously
 * @complexity Time: O(n), Space: O(n)
 */
#include <algorithm>
#include <string>

class Solution final {
public:
  [[nodiscard]] auto shortestPalindrome(const std::string& s) const -> std::string {
    constexpr unsigned long long base = 131;
    unsigned long long multiplier = 1;
    unsigned long long prefixHash = 0;
    unsigned long long suffixHash = 0;
    std::size_t palindromeEnd = 0;
    const auto n = s.size();
    
    for (std::size_t i = 0; i < n; ++i) {
      const auto charValue = static_cast<unsigned long long>(s[i] - 'a' + 1);
      prefixHash = prefixHash * base + charValue;
      suffixHash = suffixHash + multiplier * charValue;
      multiplier *= base;
      if (prefixHash == suffixHash) {
        palindromeEnd = i + 1;
      }
    }
    
    if (palindromeEnd == n) {
      return s;
    }
    
    std::string suffix = s.substr(palindromeEnd);
    std::reverse(suffix.begin(), suffix.end());
    return suffix + s;
  }
};

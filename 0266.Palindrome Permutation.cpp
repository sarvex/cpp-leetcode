/**
 * @brief Check if string can form palindrome by counting odd frequencies
 * @intuition Palindrome permutation has at most one character with odd count
 * @approach Count character frequencies, check odd count <= 1
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static auto canPermutePalindrome(const std::string& s) -> bool {
    std::array<int, 26> count{};
    for (const char c : s) {
      ++count[c - 'a'];
    }
    int oddCount = 0;
    for (const int freq : count) {
      oddCount += freq & 1;
    }
    return oddCount < 2;
  }
};

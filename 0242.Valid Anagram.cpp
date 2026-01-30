/**
 * @brief Character frequency counting for anagram validation
 * @intuition Anagrams have identical character frequencies
 * @approach Count characters, increment for s, decrement for t, all should be zero
 * @complexity Time: O(n), Space: O(1) - fixed 26 characters
 */

class Solution final {
public:
  [[nodiscard]] static auto isAnagram(const std::string& s, const std::string& t) -> bool {
    if (s.size() != t.size()) {
      return false;
    }
    std::array<int, 26> count{};
    for (std::size_t i = 0; i < s.size(); ++i) {
      ++count[s[i] - 'a'];
      --count[t[i] - 'a'];
    }
    return std::ranges::all_of(count, [](const int x) { return x == 0; });
  }
};

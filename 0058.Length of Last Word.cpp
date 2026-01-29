/**
 * @brief Find the length of the last word in a string
 * @intuition Skip trailing spaces, then count characters until next space
 * @approach Use reverse iterators and std::find_if for clarity
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto lengthOfLastWord(std::string_view s) -> int {
    auto rbegin = s.rbegin();
    auto const rend = s.rend();

    rbegin = std::find_if(rbegin, rend, [](char const ch) {
      return std::isspace(static_cast<unsigned char>(ch)) == 0;
    });

    auto const wordEnd = std::find_if(rbegin, rend, [](char const ch) {
      return std::isspace(static_cast<unsigned char>(ch)) != 0;
    });

    return static_cast<int>(std::distance(rbegin, wordEnd));
  }
};

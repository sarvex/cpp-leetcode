/**
 * @brief Convert a Roman numeral string to its integer value
 * @intuition Map Roman symbols to values; subtract if a smaller precedes larger
 * @approach Use a switch for symbol lookup, process from left to right
 * @complexity Time: O(n), Space: O(1)
 */

#include <string>

class Solution final {
public:
  [[nodiscard]] static auto romanToInt(const std::string& s) -> int {
    int result = getValue(s.back());

    for (size_t i = 0; i + 1 < s.size(); ++i) {
      const int curr = getValue(s[i]);
      const int next = getValue(s[i + 1]);
      result += (curr < next) ? -curr : curr;
    }

    return result;
  }

private:
  [[nodiscard]] static constexpr auto getValue(const char c) noexcept -> int {
    switch (c) {
      case 'I': return 1;
      case 'V': return 5;
      case 'X': return 10;
      case 'L': return 50;
      case 'C': return 100;
      case 'D': return 500;
      case 'M': return 1000;
      default: return 0;
    }
  }
};

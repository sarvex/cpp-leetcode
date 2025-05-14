#include <string>
#include <unordered_map>

class Solution final {
public:
  /**
   * @brief Convert a Roman numeral string to its integer value (C++23,
   * concise).
   * @intuition: Map Roman symbols to values, traverse, and adjust for
   * subtractive cases.
   * @approach: Use constexpr unordered_map for symbol lookup, process from left
   * to right, subtract if a smaller value precedes a larger one.
   * @complexity: O(n) time, O(1) space (n = s.size()).
   */
  int romanToInt(const std::string &s) const {
    static constexpr std::pair<char, int> romanPairs[] = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};
    static const std::unordered_map<char, int> romanMap{std::begin(romanPairs),
                                                        std::end(romanPairs)};
    int result = romanMap.at(s.back());
    for (size_t i = 0; i + 1 < s.size(); ++i) {
      const auto curr = romanMap.at(s[i]);
      const auto next = romanMap.at(s[i + 1]);
      result += (curr < next ? -curr : curr);
    }
    return result;
  }
};

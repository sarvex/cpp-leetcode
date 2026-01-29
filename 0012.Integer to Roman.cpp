/**
 * @brief Greedy mapping of integers to Roman numerals
 * @intuition Use the largest possible Roman numeral at each step
 * @approach Iterate over an array of value-numeral pairs greedily
 * @complexity Time: O(1), Space: O(1)
 */

#include <array>
#include <string>
#include <utility>

class Solution final {
public:
  [[nodiscard]] static auto intToRoman(int num) -> std::string {
    static constexpr std::array<std::pair<int, const char*>, 13> romanMap{{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    }};

    std::string result;
    for (const auto& [value, numeral] : romanMap) {
      while (num >= value) {
        num -= value;
        result += numeral;
      }
    }

    return result;
  }
};

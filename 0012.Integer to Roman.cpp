#include <array>
#include <string>
#include <string_view>
#include <utility>

/**
 * Greedy mapping of integers to Roman numerals.
 * @intuition Use the largest possible Roman numeral at each step, subtracting
 * until the number is reduced to zero.
 * @approach Iterate over a constexpr array of value-numeral pairs, greedily
 * appending numerals and subtracting values.
 * @complexity Time: O(1), Space: O(1) – input range is fixed and bounded.
 */
class Solution {
public:
  [[nodiscard]] constexpr std::string intToRoman(int num) const {
    static constexpr std::array<std::pair<int, std::string_view>, 13> romanMap{
        {{1000, "M"},
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
         {1, "I"}}};
    std::string result;
    for (const auto &[value, numeral] : romanMap) {
      while (num >= value) {
        num -= value;
        result += numeral;
      }
    }
    return result;
  }
};

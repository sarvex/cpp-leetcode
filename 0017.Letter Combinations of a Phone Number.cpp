/**
 * Generate all possible letter combinations for a phone number using mapping.
 * @intuition: Map each digit to its corresponding letters and build combinations iteratively.
 * @approach: Use a vector to store current combinations, updating it for each digit using STL algorithms and lambdas.
 * @complexity: Time O(3^n * 4^m), where n is the number of digits mapping to 3 letters, m to 4; Space O(3^n * 4^m).
 */
#include <string>
#include <vector>
#include <ranges>

class Solution {
public:
  /**
   * Return all possible letter combinations for the given digit string.
   * @param digits The input digit string ('2'-'9').
   * @return All possible letter combinations.
   */
  std::vector<std::string> letterCombinations(const std::string& digits) const {
    if (digits.empty()) return {};
    static constexpr std::array<std::string_view, 8> mapping = {
      "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    std::vector<std::string> result{ "" };
    for (const char digit : digits) {
      const auto& letters = mapping[digit - '2'];
      std::vector<std::string> next;
      for (const auto& prefix : result) {
        for (char c : letters) {
          next.push_back(prefix + c);
        }
      }
      result = std::move(next);
    }
    return result;
  }
};

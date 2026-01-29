/**
 * @brief Generate all letter combinations for a phone number
 * @intuition Map each digit to its corresponding letters and build combinations
 * @approach Use a vector to store current combinations, updating for each digit
 * @complexity Time: O(3^n * 4^m), Space: O(3^n * 4^m)
 */

#include <array>
#include <string>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto letterCombinations(const std::string& digits)
      -> std::vector<std::string> {
    if (digits.empty()) {
      return {};
    }

    static constexpr std::array<const char*, 8> mapping = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> result{""};

    for (const char digit : digits) {
      const char* letters = mapping[digit - '2'];
      std::vector<std::string> next;

      for (const auto& prefix : result) {
        for (const char* p = letters; *p != '\0'; ++p) {
          next.push_back(prefix + *p);
        }
      }

      result = std::move(next);
    }

    return result;
  }
};

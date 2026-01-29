/**
 * @brief Generate the nth term of the count-and-say sequence
 * @intuition Each term describes the previous term using run-length encoding
 * @approach Iteratively build each term by counting consecutive digits
 * @complexity Time: O(2^n), Space: O(2^n)
 */

class Solution final {
public:
  [[nodiscard]] static auto countAndSay(int n) -> std::string {
    std::string result = "1";

    while (--n > 0) {
      std::string next;
      const auto len = result.size();

      for (size_t i = 0; i < len;) {
        size_t j = i;
        while (j < len && result[j] == result[i]) {
          ++j;
        }
        next += std::to_string(j - i);
        next += result[i];
        i = j;
      }

      result = std::move(next);
    }

    return result;
  }
};

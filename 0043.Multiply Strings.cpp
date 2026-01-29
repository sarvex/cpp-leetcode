/**
 * @brief Multiply two numbers represented as strings
 * @intuition Simulate grade-school multiplication
 * @approach Multiply each digit pair, accumulate in result array, handle carries
 * @complexity Time: O(m * n), Space: O(m + n)
 */

class Solution final {
public:
  [[nodiscard]] static auto multiply(const std::string& num1,
                                     const std::string& num2) -> std::string {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    const int m = static_cast<int>(num1.size());
    const int n = static_cast<int>(num2.size());
    std::vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; --i) {
      const int a = num1[i] - '0';
      for (int j = n - 1; j >= 0; --j) {
        const int b = num2[j] - '0';
        result[i + j + 1] += a * b;
      }
    }

    for (int i = static_cast<int>(result.size()) - 1; i > 0; --i) {
      result[i - 1] += result[i] / 10;
      result[i] %= 10;
    }

    std::string answer;
    size_t start = (result[0] != 0) ? 0 : 1;
    for (size_t i = start; i < result.size(); ++i) {
      answer += static_cast<char>('0' + result[i]);
    }

    return answer;
  }
};

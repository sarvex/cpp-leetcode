/**
 * @brief Add one to a number represented as an array of digits
 * @intuition Handle carry propagation from least significant digit
 * @approach Iterate from end, increment and handle carry, insert leading 1 if needed
 * @complexity Time: O(n), Space: O(1) amortized
 */

class Solution final {
public:
  [[nodiscard]] static auto plusOne(std::vector<int>& digits) -> std::vector<int> {
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
      ++digits[i];
      digits[i] %= 10;
      if (digits[i] != 0) {
        return digits;
      }
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};

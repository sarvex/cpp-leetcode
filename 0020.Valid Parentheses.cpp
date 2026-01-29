/**
 * @brief Validate matching brackets using a stack
 * @intuition Opening brackets push; closing brackets must match top of stack
 * @approach Use a string as stack, push opens, pop and match closes
 * @complexity Time: O(n), Space: O(n)
 */

#include <string>

class Solution final {
public:
  [[nodiscard]] static auto isValid(const std::string& s) -> bool {
    std::string stack;

    for (const char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        stack.push_back(c);
      } else if (stack.empty() || !matches(stack.back(), c)) {
        return false;
      } else {
        stack.pop_back();
      }
    }

    return stack.empty();
  }

private:
  [[nodiscard]] static constexpr auto matches(char left, char right) noexcept
      -> bool {
    return (left == '(' && right == ')') || (left == '[' && right == ']') ||
           (left == '{' && right == '}');
  }
};

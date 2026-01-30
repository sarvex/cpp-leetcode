/**
 * @brief Stack-based expression evaluation with parentheses
 * @intuition Use stack to save state when entering parentheses
 * @approach Track running sum and sign, push state on '(', restore on ')'
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto calculate(const std::string& s) -> int {
    std::stack<int> stk;
    int result = 0;
    int sign = 1;
    const auto n = s.size();
    
    for (std::size_t i = 0; i < n; ++i) {
      const char c = s[i];
      if (std::isdigit(c)) {
        int num = 0;
        while (i < n && std::isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          ++i;
        }
        result += sign * num;
        --i;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '(') {
        stk.push(result);
        stk.push(sign);
        result = 0;
        sign = 1;
      } else if (c == ')') {
        result *= stk.top();
        stk.pop();
        result += stk.top();
        stk.pop();
      }
    }
    return result;
  }
};

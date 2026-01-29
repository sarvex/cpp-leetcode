/**
 * @brief Stack-based calculator with operator precedence
 * @intuition Handle * and / immediately, defer + and - using stack
 * @approach Push values for +/-, compute immediately for *//, sum stack at end
 * @complexity Time: O(n), Space: O(n)
 */
#include <cctype>
#include <stack>
#include <string>

class Solution final {
public:
  [[nodiscard]] auto calculate(const std::string& s) const -> int {
    int currentNum = 0;
    char prevOp = '+';
    std::stack<int> stk;
    const auto n = s.size();
    
    for (std::size_t i = 0; i < n; ++i) {
      const char c = s[i];
      if (std::isdigit(c)) {
        currentNum = currentNum * 10 + (c - '0');
      }
      if (i == n - 1 || c == '+' || c == '-' || c == '*' || c == '/') {
        if (prevOp == '+') {
          stk.push(currentNum);
        } else if (prevOp == '-') {
          stk.push(-currentNum);
        } else if (prevOp == '*') {
          const int top = stk.top();
          stk.pop();
          stk.push(top * currentNum);
        } else if (prevOp == '/') {
          const int top = stk.top();
          stk.pop();
          stk.push(top / currentNum);
        }
        prevOp = c;
        currentNum = 0;
      }
    }
    
    int result = 0;
    while (!stk.empty()) {
      result += stk.top();
      stk.pop();
    }
    return result;
  }
};

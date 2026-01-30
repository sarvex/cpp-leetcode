/**
 * @brief Evaluate RPN expression using stack
 * @intuition Operands go on stack, operators pop two and push result
 * @approach Use stack to track operands, apply operators as encountered
 * @complexity Time: O(n), Space: O(n)
 */

#include <cctype>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution final {
public:
    [[nodiscard]] static auto evalRPN(vector<string>& tokens) -> int {
        stack<int> operands;

        for (const auto& token : tokens) {
            if (token.size() > 1 || std::isdigit(static_cast<unsigned char>(token[0]))) {
                operands.push(std::stoi(token));
            } else {
                const int right = operands.top();
                operands.pop();
                const int left = operands.top();
                operands.pop();

                switch (token[0]) {
                    case '+':
                        operands.push(left + right);
                        break;
                    case '-':
                        operands.push(left - right);
                        break;
                    case '*':
                        operands.push(left * right);
                        break;
                    case '/':
                        operands.push(left / right);
                        break;
                }
            }
        }

        return operands.top();
    }
};

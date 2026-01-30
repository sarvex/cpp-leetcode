/**
 * @brief Stack-based parsing of boolean expressions
 * @intuition Use a stack to track operators and operands, evaluating when closing parenthesis is found
 * @approach Push operators and boolean values onto stack. When ')' is encountered, pop all booleans
 *           until finding the operator, then evaluate and push the result.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool parseBoolExpr(const string& expression) {
        stack<char> stk;
        for (char c : expression) {
            if (c != '(' && c != ')' && c != ',') {
                stk.push(c);
            } else if (c == ')') {
                int t = 0, f = 0;
                while (stk.top() == 't' || stk.top() == 'f') {
                    t += stk.top() == 't';
                    f += stk.top() == 'f';
                    stk.pop();
                }
                char op = stk.top();
                stk.pop();
                if (op == '!') c = f ? 't' : 'f';
                if (op == '&') c = f ? 'f' : 't';
                if (op == '|') c = t ? 't' : 'f';
                stk.push(c);
            }
        }
        return stk.top() == 't';
    }
};

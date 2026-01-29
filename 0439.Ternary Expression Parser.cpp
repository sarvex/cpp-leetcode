/**
 * @brief Parse ternary expression string (a?b:c) to result
 * @intuition Process right to left using stack, resolve ? when encountered
 * @approach Reverse string, push operands, pop and evaluate on '?'
 * @complexity Time: O(n) Space: O(n)
 */
#include <algorithm>
#include <string>

class Solution final {
public:
    [[nodiscard]] auto parseTernary(std::string expression) const -> std::string {
        std::string stk;
        bool cond = false;

        std::reverse(expression.begin(), expression.end());

        for (const char c : expression) {
            if (c == ':') {
                continue;
            }
            if (c == '?') {
                cond = true;
            } else {
                if (cond) {
                    if (c == 'T') {
                        const char x = stk.back();
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(x);
                    } else {
                        stk.pop_back();
                    }
                    cond = false;
                } else {
                    stk.push_back(c);
                }
            }
        }

        return {stk[0]};
    }
};

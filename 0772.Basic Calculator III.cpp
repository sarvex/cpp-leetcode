/**
 * @brief Basic calculator with +, -, *, / and parentheses
 * @intuition Use two stacks: one for operands, one for operators with precedence
 * @approach Shunting-yard algorithm: handle precedence and parentheses
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int calculate(const std::string& s) {
        std::array<int, 128> priority{};
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;
        priority['('] = priority[')'] = 0;

        std::stack<char> ops;
        std::stack<int> nums;
        const int n = static_cast<int>(s.size());

        auto compute = [](int b, char op, int a) -> int {
            switch (op) {
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': return a / b;
                default: return 0;
            }
        };

        for (int i = 0; i < n; ++i) {
            const char ch = s[i];
            if (ch == ' ') continue;

            if (ch >= '0' && ch <= '9') {
                int num = ch - '0';
                while (i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num = num * 10 + (s[++i] - '0');
                }
                nums.push(num);
            } else if (ops.empty() || ch == '(' || priority[ch] > priority[ops.top()]) {
                if (nums.empty() && (ch == '-' || ch == '+')) {
                    nums.push(0);
                }
                ops.push(ch);
                if (ch == '(') {
                    int j = i;
                    while (j + 1 < n && s[j + 1] == ' ') ++j;
                    if (j + 1 < n && (s[j + 1] == '-' || s[j + 1] == '+')) {
                        nums.push(0);
                    }
                }
            } else if (ch == ')') {
                while (ops.top() != '(') {
                    const int a = nums.top(); nums.pop();
                    const int b = nums.top(); nums.pop();
                    nums.push(compute(a, ops.top(), b));
                    ops.pop();
                }
                ops.pop();
            } else {
                while (!ops.empty() && priority[ch] <= priority[ops.top()] && ops.top() != '(') {
                    const int a = nums.top(); nums.pop();
                    const int b = nums.top(); nums.pop();
                    nums.push(compute(a, ops.top(), b));
                    ops.pop();
                }
                ops.push(ch);
            }
        }

        while (!ops.empty()) {
            const int a = nums.top(); nums.pop();
            const int b = nums.top(); nums.pop();
            nums.push(compute(a, ops.top(), b));
            ops.pop();
        }

        return nums.top();
    }
};

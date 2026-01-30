/**
 * @brief Stack-based arithmetic evaluation with cycling operators
 * @intuition Apply *, /, +, - in cycle; handle precedence using stack
 * @approach Push values to stack, multiply/divide top, add positive, subtract negative
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int clumsy(const int n) {
        std::stack<int> stk;
        stk.push(n);
        int k = 0;
        for (int x = n - 1; x; --x) {
            if (k == 0) {
                stk.top() *= x;
            } else if (k == 1) {
                stk.top() /= x;
            } else if (k == 2) {
                stk.push(x);
            } else {
                stk.push(-x);
            }
            k = (k + 1) % 4;
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

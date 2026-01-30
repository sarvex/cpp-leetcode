/**
 * @brief Validate if push/pop sequence is valid for stack
 * @intuition Simulate stack operations; pop when top matches next pop element
 * @approach Push elements; after each push, pop while top matches pop sequence
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (const int x : pushed) {
            stk.push(x);
            while (!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return i == static_cast<int>(popped.size());
    }
};

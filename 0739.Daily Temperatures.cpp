/**
 * @brief Days until warmer temperature using monotonic stack
 * @intuition Maintain decreasing stack of indices; pop when warmer day found
 * @approach Process from right, stack holds indices of unresolved warmer days
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        std::stack<int> stack;
        std::vector<int> result(n);
        
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && temperatures[stack.top()] <= temperatures[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                result[i] = stack.top() - i;
            }
            stack.push(i);
        }
        return result;
    }
};

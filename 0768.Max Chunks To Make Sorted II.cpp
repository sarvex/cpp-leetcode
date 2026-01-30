/**
 * @brief Maximum chunks to sort array with duplicates
 * @intuition Each chunk's max must be <= min of remaining elements
 * @approach Monotonic stack: maintain chunk maximums, merge when needed
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxChunksToSorted(const std::vector<int>& arr) {
        std::stack<int> stack;
        
        for (const int val : arr) {
            if (stack.empty() || stack.top() <= val) {
                stack.push(val);
            } else {
                const int maxVal = stack.top();
                stack.pop();
                while (!stack.empty() && stack.top() > val) {
                    stack.pop();
                }
                stack.push(maxVal);
            }
        }
        return static_cast<int>(stack.size());
    }
};

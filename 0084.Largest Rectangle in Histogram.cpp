/**
 * @brief Monotonic stack for largest rectangle in histogram
 * @intuition Stack tracks potential rectangle boundaries; pop when smaller height found
 * @approach Single-pass with stack of indices; calculate areas when popping larger heights
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto largestRectangleArea(const vector<int>& heights) -> int {
        if (heights.empty()) {
            return 0;
        }

        long long maxArea = 0;
        stack<size_t> indices;
        const size_t n = heights.size();

        for (size_t i = 0; i <= n; ++i) {
            const int currHeight = (i == n) ? 0 : heights[i];

            while (!indices.empty() && heights[indices.top()] > currHeight) {
                const auto height = static_cast<long long>(heights[indices.top()]);
                indices.pop();

                const auto width = static_cast<long long>(
                    i - (indices.empty() ? 0 : indices.top() + 1)
                );
                maxArea = max(maxArea, height * width);
            }
            indices.push(i);
        }

        return static_cast<int>(maxArea);
    }
};

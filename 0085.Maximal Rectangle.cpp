/**
 * @brief Maximal rectangle using histogram approach per row
 * @intuition Treat each row as base of histogram; find largest rectangle in each
 * @approach Build height array incrementally; apply largest rectangle algorithm per row
 * @complexity Time: O(m * n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto maximalRectangle(const vector<vector<char>>& matrix) -> int {
        const int n = static_cast<int>(matrix[0].size());
        vector<int> heights(n, 0);
        int result = 0;
        
        for (const auto& row : matrix) {
            for (int j = 0; j < n; ++j) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

private:
    [[nodiscard]] static auto largestRectangleArea(const vector<int>& heights) -> int {
        const int n = static_cast<int>(heights.size());
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
        return result;
    }
};

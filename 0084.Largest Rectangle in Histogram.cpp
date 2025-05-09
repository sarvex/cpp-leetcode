/**
 * @brief Finds largest rectangle area in histogram using monotonic stack
 * 
 * @intuition: For each bar, if we can find the first smaller bar on left and right,
 * we can calculate the maximum rectangle area with current bar as height
 * 
 * @approach: Use monotonic stack to find first smaller element on left and right
 * - Maintain a monotonically increasing stack
 * - For each bar, while stack top is >= current, pop and update right boundary
 * - Current stack top becomes left boundary for current element
 * - Finally calculate area using (right - left - 1) * height
 * 
 * @complexity Time: O(n) where n is size of input array, each element pushed/popped once
 * @complexity Space: O(n) for stack and boundary arrays
 */
class Solution {
    using Index = int;
    using Height = int;
    using Area = int;
    
private:
    struct Boundaries {
        std::vector<Index> left;
        std::vector<Index> right;
        
        explicit Boundaries(const std::size_t size) 
            : left(size, -1), right(size, size) {}
    };
    
    static Boundaries findBoundaries(const std::vector<Height>& heights) {
        const auto n = heights.size();
        Boundaries bounds(n);
        std::stack<Index> monoStack;
        
        for (Index i = 0; i < n; ++i) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                bounds.right[monoStack.top()] = i;
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                bounds.left[i] = monoStack.top();
            }
            monoStack.push(i);
        }
        
        return bounds;
    }
    
    static Area calculateMaxArea(const std::vector<Height>& heights, 
                               const Boundaries& bounds) {
        Area maxArea = 0;
        for (Index i = 0; i < heights.size(); ++i) {
            const auto width = bounds.right[i] - bounds.left[i] - 1;
            maxArea = std::max(maxArea, heights[i] * width);
        }
        return maxArea;
    }

public:
    Area largestRectangleArea(const std::vector<Height>& heights) {
        if (heights.empty()) return 0;
        
        auto bounds = findBoundaries(heights);
        return calculateMaxArea(heights, bounds);
    }
};
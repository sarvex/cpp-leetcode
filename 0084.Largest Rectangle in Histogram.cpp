#include <stack>
#include <vector>

/**
 * Optimized largest rectangle area in histogram using std::ranges and concepts
 *
 * @intuition: Use monotonic stack to find boundaries efficiently in one pass
 * Utilize stack to track potential rectangle boundaries, popping when we find smaller heights
 *
 * @approach: Single-pass monotonic stack with optimized memory usage
 * - Use std::ranges for cleaner iteration
 * - Maintain stack of indices for potential rectangle boundaries
 * - When current height is smaller, calculate areas for all larger heights in stack
 * - Track max area during the process to avoid extra array allocations
 *
 * @complexity Time: O(n), single pass through array with each element pushed/popped once
 * @complexity Space: O(n) for the monotonic stack in worst case
 */
class Solution {
    using Height = int;
    using Index = std::size_t;
    using Area = long long; // Use long long to prevent overflow

public:
    Area largestRectangleArea(const std::vector<Height>& heights) const {
        if (heights.empty()) return 0;

        Area maxArea = 0;
        std::stack<Index> indices;

        // Process all bars, including an implicit zero-height bar at the end
        for (Index i = 0; i <= heights.size(); ++i) {
            const auto currHeight = (i == heights.size()) ? 0 : heights[i];

            // Process stored indices while we can extend rectangles
            while (!indices.empty() && heights[indices.top()] > currHeight) {
                const auto height = heights[indices.top()];
                indices.pop();

                // Calculate width based on boundaries
                const auto width = static_cast<Area>(
                    i - (indices.empty() ? 0 : indices.top() + 1)
                );
                maxArea = std::max(maxArea, height * width);
            }
            indices.push(i);
        }

        return maxArea;
    }
};

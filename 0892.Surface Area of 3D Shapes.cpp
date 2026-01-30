/**
 * @brief Calculate total surface area of 3D shape on grid
 * @intuition Each tower contributes top/bottom + sides minus hidden faces between neighbors
 * @approach For each non-zero cell: add 2 (top + bottom) + 4*height (sides).
 *           Subtract 2*min(heights) for each adjacent pair (hidden faces).
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto surfaceArea(
        const std::vector<std::vector<int>>& grid) -> int {
        const int n = static_cast<int>(grid.size());
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans += 2 + grid[i][j] * 4;
                    if (i > 0) {
                        ans -= std::min(grid[i][j], grid[i - 1][j]) * 2;
                    }
                    if (j > 0) {
                        ans -= std::min(grid[i][j], grid[i][j - 1]) * 2;
                    }
                }
            }
        }
        return ans;
    }
};

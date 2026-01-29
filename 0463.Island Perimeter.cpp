/**
 * @brief Calculate perimeter of island in grid
 * @intuition Each land cell contributes 4, minus 2 for each adjacent land
 * @approach Count cells, subtract shared edges with right and bottom neighbors
 * @complexity Time: O(m*n) Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto islandPerimeter(const std::vector<std::vector<int>>& grid) const -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        ans -= 2;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        ans -= 2;
                    }
                }
            }
        }

        return ans;
    }
};

/**
 * @brief Calculate three orthogonal projections of 3D grid
 * @intuition XY = non-zero cells, YZ = max per row, ZX = max per column
 * @approach Count non-zero cells for XY projection. Track row maximums for YZ
 *           and column maximums for ZX. Sum all three projections.
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto projectionArea(
        const std::vector<std::vector<int>>& grid) -> int {
        const int n = static_cast<int>(grid.size());
        int xy = 0, yz = 0, zx = 0;
        
        for (int i = 0; i < n; ++i) {
            int maxYz = 0, maxZx = 0;
            for (int j = 0; j < n; ++j) {
                xy += (grid[i][j] > 0);
                maxYz = std::max(maxYz, grid[i][j]);
                maxZx = std::max(maxZx, grid[j][i]);
            }
            yz += maxYz;
            zx += maxZx;
        }
        return xy + yz + zx;
    }
};

/**
 * @brief Calculate maximum building height increase preserving skyline
 * @intuition Each building can grow to min of its row max and column max
 * @approach Precompute row and column maximums. Each building can be increased
 *           to the minimum of these two values. Sum all possible increases.
 * @complexity Time: O(m * n), Space: O(m + n)
 */
class Solution final {
public:
    [[nodiscard]] static auto maxIncreaseKeepingSkyline(
        const std::vector<std::vector<int>>& grid) -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        
        std::vector<int> rowMax(m);
        std::vector<int> colMax(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = std::max(rowMax[i], grid[i][j]);
                colMax[j] = std::max(colMax[j], grid[i][j]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += std::min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

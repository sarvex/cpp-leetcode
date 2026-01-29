/**
 * @brief Find cell to place bomb that kills maximum enemies
 * @intuition Precompute enemies killed in all four directions
 * @approach Scan each direction, accumulate counts stopping at walls
 * @complexity Time: O(mn), Space: O(mn)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int maxKilledEnemies(const std::vector<std::vector<char>>& grid) const {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        std::vector<std::vector<int>> kills(m, std::vector<int>(n));
        
        // Count from left and right
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    count = 0;
                } else if (grid[i][j] == 'E') {
                    ++count;
                }
                kills[i][j] += count;
            }
            count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    count = 0;
                } else if (grid[i][j] == 'E') {
                    ++count;
                }
                kills[i][j] += count;
            }
        }
        
        // Count from top and bottom
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') {
                    count = 0;
                } else if (grid[i][j] == 'E') {
                    ++count;
                }
                kills[i][j] += count;
            }
            count = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    count = 0;
                } else if (grid[i][j] == 'E') {
                    ++count;
                }
                kills[i][j] += count;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    ans = std::max(ans, kills[i][j]);
                }
            }
        }
        return ans;
    }
};

/**
 * @brief DFS with memoization for longest increasing path in matrix
 * @intuition From each cell, explore all four directions for increasing values
 * @approach DFS with memoization, each cell stores longest path starting from it
 * @complexity Time: O(mn), Space: O(mn)
 */
#include <algorithm>
#include <array>
#include <functional>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int longestIncreasingPath(std::vector<std::vector<int>>& matrix) const {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
        int ans = 0;
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};

        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (memo[i][j] != 0) {
                return memo[i][j];
            }
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    memo[i][j] = std::max(memo[i][j], dfs(x, y));
                }
            }
            return ++memo[i][j];
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = std::max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};

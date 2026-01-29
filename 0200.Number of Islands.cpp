/**
 * @brief Count connected components using DFS flood fill
 * @intuition Each island is a connected component of '1's
 * @approach DFS from each unvisited '1', mark visited by changing to '0'
 * @complexity Time: O(m*n), Space: O(m*n) for recursion stack
 */

class Solution final {
public:
    [[nodiscard]] static auto numIslands(std::vector<std::vector<char>>& grid) -> int {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        int count = 0;
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            grid[i][j] = '0';
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                    dfs(x, y);
                }
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++count;
                }
            }
        }
        
        return count;
    }
};

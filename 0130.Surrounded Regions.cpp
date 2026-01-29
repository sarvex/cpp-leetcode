/**
 * @brief Capture surrounded regions using boundary DFS
 * @intuition O's connected to boundary cannot be captured, mark them first
 * @approach DFS from boundary O's marking as safe, then flip remaining O's to X
 * @complexity Time: O(m*n), Space: O(m*n) for recursion stack
 */

#include <array>
#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution final {
public:
    auto solve(vector<vector<char>>& board) -> void {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
                return;
            }
            board[i][j] = '.';
            for (int k = 0; k < 4; ++k) {
                dfs(i + dirs[k], j + dirs[k + 1]);
            }
        };
        
        // Mark boundary-connected O's
        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        
        // Flip remaining O's to X, restore marked cells to O
        for (auto& row : board) {
            for (auto& cell : row) {
                if (cell == '.') {
                    cell = 'O';
                } else if (cell == 'O') {
                    cell = 'X';
                }
            }
        }
    }
};

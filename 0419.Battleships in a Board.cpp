/**
 * @brief Count battleships in board without modifying it (O(1) extra space)
 * @intuition Only count top-left cell of each battleship
 * @approach Skip 'X' cells that have 'X' above or to the left
 * @complexity Time: O(m*n) Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto countBattleships(const std::vector<std::vector<char>>& board) const -> int {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
                ++ans;
            }
        }

        return ans;
    }
};
